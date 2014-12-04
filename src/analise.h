#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#define MAX 100

/* structs */
struct stat st = {0};

typedef struct _Error
{
	char nome[7];
	int qnt;
}Error;

typedef struct _AnaliseAluno{
	char nome[40];
	char exercicio[40];
	int qntLinhas;
	int qntErros;
	Error error[20];
	struct _AnaliseAluno * proximo;
}AnaliseAluno;

typedef struct _Comment
{
	int existe;
	int possui;
}Comment;

typedef struct _Variaveis
{
	int linha;
	int utilizada;
	char var[15];
	char tipo[10];
	char escopo[15];
	struct _Variaveis * proximo;
}Variaveis;

typedef struct _ChamadaVariavel
{
	int linha;
	char estrutura[15];
}ChamadaVariavel;

typedef struct _SaidaAnalise
{
	char erro[7];
    int contL;
    int contE;
    int nec;
    int uti;
    char strAux[15];
    struct _SaidaAnalise * proximo;
}SaidaAnalise;

typedef struct _SaidaError
{
	char palavra[15];
	char str[50];
	int linha;
	int espaco;
	struct _SaidaError * proximo;
}SaidaError;

/* variaveis globais */
extern int espacos;
extern int linhas_puladas;
extern int contadorDeLinhas;
extern int OK;
extern int contadorEspacos;
extern int usouTab;
extern int terminou;
extern Comment comment_criador, comment_prototipo, comment_include, comment_main, comment_funcoes, comment_vglobais;
extern FILE * yyin;

int totalError, tab = 0;
Error error[20];
SaidaAnalise * saidaAna;
SaidaError * saidaError;
Variaveis * varDeclaradas;
Variaveis * varUsadas;
AnaliseAluno * analiseAluno;
char exAtual[40], alunoAtual[40], arqAtual[40];

/* prototipos */
void inicializaAnalise();
void analise(int, int);
void analiseBloco(int, char[]);
void addError(char[7]);
void inserirSaidaAnalise(int, int, char[], char[], int, int);
SaidaAnalise * addSaidaAnalise(int, int, char[7], char[15], int, int);
void imprimeAnalise();

Variaveis * addVar(int, char[], char[], char[]);
void inserirVar(Variaveis **, char[],char[], char[]);

/* Dados */
void entradaArquivoAluno(char[]);
void saidaArquivoAluno(char[]);
void inserirDadosAluno(AnaliseAluno **, char[], int, int, Error[]);
void imprimeAnaliseAluno();

/* Analise */
void analisaExercicio(char[]);
void saidaArquivoExercicio();

void inicializaAnalise()
{
	int i;
 	contadorDeLinhas = 1;
 	analiseAluno = NULL;
	varDeclaradas = NULL;
	varUsadas = NULL;
	saidaError = NULL;
	saidaAna = NULL;
	espacos = 0;
	linhas_puladas = 0;
	totalError = 0;
	OK = 1;
	for(i = 0; i < 20; i++)
	{
		char aux[2];
		sprintf(aux, "%d", i);
		strcpy(error[i].nome, "Error");
		if(i < 10)
			strcat(error[i].nome, "0");
		strcat(error[i].nome, aux);
		error[i].qnt = 0;
	}

	comment_criador.possui = 0;
	comment_prototipo.possui = 0;
	comment_include.possui = 0;
	comment_main.possui = 0;
	comment_vglobais.possui = 0;
}

/* Funcoes das Analises */
void analise(int e, int l)
{
	char erro[7];
	char strLinha[3];
	char strSaida[200];


	contadorEspacos++;
	if(linhas_puladas != l)
	{
		OK = 0;
		strcpy(erro, "Error02");
		addError(erro);
		inserirSaidaAnalise(contadorDeLinhas, contadorEspacos, erro, "", l, linhas_puladas);
		//printf("Linha %d --%s - Linhas necessarias: %d, Linhas utilizadas: %d\n", contadorDeLinhas , erro, l, linhas_puladas);
	}
	if(usouTab == 1)
	{
		OK = 0;
		inserirSaidaAnalise(contadorDeLinhas, contadorEspacos, "Error03", "", 0, 0); 
		addError("Error03");
	}
	else if(espacos != e && usouTab == 0)
	{	
		strcpy(erro, "Error01");
		addError(erro);
		OK = 0;
		inserirSaidaAnalise(contadorDeLinhas, contadorEspacos, erro, "", e, espacos);
		//printf("Linha %d -- %s - Espacos necessarios: %d, Espacos utilizados: %d\n", contadorDeLinhas, erro, e, espacos);
		
	}
	usouTab = 0;
	linhas_puladas = 0;
	espacos = 0;
}

void analiseBloco(int inicioBloco, char strAux[15])
{
	char erro[7];
	if(inicioBloco != 1)
	{
		strcpy(erro, "Error04");
		addError(erro);
		OK = 0;
		inserirSaidaAnalise(contadorDeLinhas, contadorEspacos, erro, strAux, 0, 0);
	}
}

/* Funcoes de Tabulacoes */
void addTab()
{
	tab = tab + 4;
}

void remTab()
{
	tab = tab - 4;
}

int getTab()
{
	return tab;
}

/* Funcoes de Erros */
void addError(char nome[7])
{
	char str_valor[2];
	int nError;

	str_valor[0] = nome[5];
	str_valor[1] = nome[6];

	nError = atoi(str_valor);

	error[nError].qnt++;
	totalError++;
}

SaidaAnalise * addSaidaAnalise(int contL, int contE, char erro[7], char strAux[15], int nec, int uti)
{
    SaidaAnalise * add = (SaidaAnalise*) malloc(sizeof(SaidaAnalise));
    strcpy(add->strAux, strAux);
    add->contL = contL;
    add->contE = contE;
    add->nec = nec;
    add->uti = uti;
    add->proximo == NULL;
    strcpy(add->erro, erro);

    return add;
}

void inserirSaidaAnalise(int contL, int contE, char erro[7], char strAux[15], int nec, int uti)
{
	SaidaAnalise * aux = addSaidaAnalise(contL, contE, erro, strAux, nec, uti);

	if(saidaAna == NULL)
	{
		saidaAna = aux;
	}
	else
	{
		SaidaAnalise * aux2 = saidaAna;
		while(aux2->proximo != NULL)
		{
			aux2 = aux2->proximo;
		}
		aux2->proximo = aux;
	}
}

void imprimeAnalise()
{
	SaidaAnalise * aux = saidaAna;
	while(aux != NULL)
	{
		if(!(strcmp(aux->erro, "Error01")))
		{
			if(aux->nec - aux->uti > 0)
				printf("%s:%d:%d -- %s: Espacamento em falta, por favor, acrescentar < %d > espaco(s).\n", arqAtual, aux->contL, aux->contE, aux->erro, aux->nec - aux->uti);
			else
				printf("%s:%d:%d -- %s: Espacamento em excesso, por favor, apagar < %d > espaco(s).\n", arqAtual, aux->contL, aux->contE, aux->erro, aux->uti - aux->nec);
		}
		else if(!(strcmp(aux->erro, "Error02")))
		{
			printf("%s:%d:%d -- %s - Quebra de linhas em ",arqAtual, aux->contL, aux->contE, aux->erro);
			if(aux->nec - aux->uti > 0)
				printf("falta, por favor, acrescentar < %d > linha(s).\n", aux->nec - aux->uti);
			else
				printf("excesso, por favor, apagar < %d > linha(s).\n", aux->uti - aux->nec);
		}
		else if(!(strcmp(aux->erro, "Error03")))
		{
			printf("%s:%d:%d -- %s: Nao utilizar tabulacoes, por favor, troque por < %d > espacamentos.\n", arqAtual, aux->contL, aux->contE, aux->erro, getTab());
		}
		else if(!(strcmp(aux->erro, "Error04")))
		{
			printf("%s:%d:%d -- %s: Declaracao da variavel \"%s\" nao se encontra no inicio do bloco.\n", arqAtual, aux->contL, aux->contE, aux->erro, aux->strAux);
		}
		else if(!(strcmp(aux->erro, "Error10")))
		{
			printf("%s:%d:%d -- %s: Variavel \"%s\" declarada nao utilizada.\n", arqAtual, aux->contL, aux->contE, aux->erro, aux->strAux);
		}
		aux = aux->proximo;
	}

}


Variaveis * addVar(int linha, char tipo[10], char var[15], char escopo[15])
{
	Variaveis * add = (Variaveis*) malloc(sizeof(Variaveis));
	add->linha = linha;
	strcpy(add->tipo, tipo);
	strcpy(add->var, var);
	strcpy(add->escopo, escopo);
	add->proximo = NULL;
	add->utilizada = 0;

	return add;
}
void inserirVar(Variaveis ** variaveis, char tipo[10], char var[15], char escopo[15])
{
	Variaveis * aux = addVar(contadorDeLinhas, tipo, var, escopo);

	if(*variaveis == NULL)
	{
		*variaveis = aux;
	}
	else
	{
		Variaveis * aux2 = *variaveis;
		while(aux2->proximo != NULL)
		{
			if(!strcmp(aux->var, aux2->var) && !strcmp(aux->escopo, aux2->escopo))
				return;
			aux2 = aux2->proximo;
		}
		aux2->proximo = aux;
	}
}

void analisaVariaveis()
{
	Variaveis * declaradas = varDeclaradas;
	Variaveis * usadas = varUsadas;
	Variaveis * aux;
	char erro[7];

	aux = usadas;
	while(aux != NULL)
	{
		Variaveis * aux2;
		int encontrou = 0;

		aux2 = declaradas;
		while(aux2 != NULL)
		{
			if(!strcmp(aux->var, aux2->var) )//&& !strcmp(aux->escopo, aux2->escopo))
			{
				aux2->utilizada = 1;
				break;
			}
			aux2 = aux2->proximo;
		}
		aux = aux->proximo;
	}

	aux = declaradas;
	while(aux != NULL)
	{
		if(aux->utilizada == 0)
		{
			OK = 0;
			strcpy(erro, "Error10");
			addError(erro);
			inserirSaidaAnalise(aux->linha, 2, erro, aux->var, 0, 0);
		}
		aux = aux->proximo;
	}
}

void imprimeVarUsadas()
{
	Variaveis * aux = varUsadas;

	while(aux != NULL)
	{
		printf("var: %s\n", aux->var);
		aux = aux->proximo;
	}
}

SaidaError * addSaidaError(char palavra[15], char str[45], int linha, int espaco)
{
	SaidaError * add = (SaidaError*) malloc(sizeof(SaidaError));
	strcpy(add->palavra, palavra);
	strcpy(add->str, str);
	add->linha = linha;
	add->espaco = espaco;
	add->proximo = NULL;

	return add;
}
void inserirSaidaError(char palavra[15], char str[45], int linha, int espaco)
{
	SaidaError * add = addSaidaError(palavra, str, linha, espaco);

	if(saidaError == NULL)
	{
		saidaError = add;
	}
	else
	{
		SaidaError * aux = saidaError;
		while(aux->proximo != NULL)
		{
			
		}
	}
}

void imprimeSaidaError()
{
	SaidaError * aux = saidaError;

	while(aux != NULL)
	{
		printf("Linha: %d, erro encontrado! %s\n", aux->linha, aux->palavra);
		aux = aux->proximo;
	}
}


/*INICIO DO PROGRAMA
* INSERIR NOME E Tabulacoes
*/

void inicializaVariaveis()
{
	comment_criador.possui = 0;
	comment_prototipo.possui = 0;
	comment_include.possui = 0;
	comment_main.possui = 0;
	comment_vglobais.possui = 0;

}

void inicio()
{
	char ex[30];
	char arq[40], arq2[40], arq3[40], arqAnaliseAluno[40];
	char aluno[30];
	char dir[30], dirExercicios[30], dirEntradaEx[30], dirAlunos[30], dirEntradaAl[30];
	int result, i;
	DIR *d;
	struct dirent * pasta;
	strcpy(dir, ".");
	strcpy(dirExercicios, dir);
	strcat(dirExercicios, "/exercicios");
	strcpy(dirAlunos, dir);
	strcat(dirAlunos, "/alunos");

	if(stat(dirExercicios, &st) == -1)
	{
		mkdir(dirExercicios, 0777);
	}
	if(stat(dirAlunos, &st) == -1)
		mkdir(dirAlunos, 0777);

	d = opendir(dir);

	printf("exercicio: ");
	scanf("%s", ex);

	for(i = 0; ex[i] != '\0'; i++);
	if(ex[i-2] != '.' || ex[i-1] != 'c')
	{
		printf("Extensao do exercicio invalido.");
		printf("\nApenas arquivos \".c\" sao permitidos. Abortando ...\n");
		exit(1);
	}

	printf("entradas analisadas:");
	strcpy(arq, dir);
	strcat(arq, "/");
	strcpy(dirEntradaEx, dirExercicios);
	strcat(dirEntradaEx, "/");
	strcat(dirEntradaEx, ex);
	for(i = 2; dirEntradaEx[i] != '.' ;i++);
		dirEntradaEx[i] = '\0';
	strcpy(exAtual, ex); //Global Exercicio
	for(i = 0; exAtual[i] != '.' ;i++);
		exAtual[i] = '\0';

	if(stat(dirEntradaEx, &st) != -1)
	{
		d = opendir(dirEntradaEx);
	}

	/*
	* Bloco imenso de optencao de dados
	*/
	if(d)
	{
		result = 0;
		while((pasta = readdir(d)) != NULL)
		{
			if(strstr(pasta->d_name, ex))
			{
				strcpy(arqAtual, pasta->d_name);
				if(stat(dirExercicios, &st) == -1)
				{
					mkdir(dirEntradaEx, 0777);
				}
				
				for(i = 0; pasta->d_name[i] != '_'; i++)
				{
					aluno[i] = pasta->d_name[i];
				}
				aluno[i] = '\0';
				strcpy(alunoAtual, aluno); //global para acessar

				strcpy(dirEntradaAl, dirAlunos);
				strcat(dirEntradaAl, "/");
				strcat(dirEntradaAl, aluno);
				if(stat(dirEntradaAl, &st) == -1)
				{
					mkdir(dirEntradaAl, 0777);
				}

				strcpy(arq2, arq);
				strcat(arq2, pasta->d_name);
				strcpy(arq3, dirEntradaAl);
				strcat(arq3, "/");
				strcat(arq3, pasta->d_name);
				remove(arq3);
				rename(arq2,arq3);

				FILE * myfile = fopen(arq3, "r");
				result = 1;
				yyin = myfile;
				printf("\n%s", pasta->d_name);
				inicializaAnalise();
				yyparse();
				fclose(myfile);

				if(terminou)
				{
					analisaVariaveis();
					int i = 0;

					imprimeSaidaError();
					if(OK)
						printf("--OK!");
					else
					{
						printf("\n");
						imprimeAnalise();
						printf("\n");
						printf("\nTotal de erros: %d\n", totalError);
						for(i = 0; i < 20 ; i++)
						{
							if(error[i].qnt > 0)
							{
								printf("%s: %d\n", error[i].nome, error[i].qnt);
							}
						}
					}
					printf("\n");
					strcpy(arqAnaliseAluno, dirEntradaAl);
					strcat(arqAnaliseAluno, "/");
					strcat(arqAnaliseAluno, alunoAtual);
					strcat(arqAnaliseAluno, ".txt");
					entradaArquivoAluno(arqAnaliseAluno);
					inserirDadosAluno(&analiseAluno, ex, contadorDeLinhas, totalError, error);
					saidaArquivoAluno(arqAnaliseAluno);
					//imprimeAnaliseAluno();
					//arquivoAluno(arqAnaliseAluno);
				}
			}
		}
		if(result == 0)
		{
			printf("Arquivo nao encontrado. Abortando...\n");
			exit(1);
		}
		closedir(d);
	}

	analisaExercicio(ex);
}


/* MECHENDO COM MANIPULACAO DE DADOS, AQUI QUE O BIXO PEGA */

AnaliseAluno * addAnaliseAluno(char exercicio[40], int qntLinhas, int qntErros, Error erros[20])
{
	AnaliseAluno * add = (AnaliseAluno*) malloc(sizeof(AnaliseAluno));
	int i;
	strcpy(add->exercicio, exercicio);
	add->qntLinhas = qntLinhas;
	add->qntErros = qntErros;
	for(i = 0; i < 20; i++)
	{
		strcpy(add->error[i].nome, erros[i].nome);
		add->error[i].qnt = erros[i].qnt;
	}
	add->proximo = NULL;

	return add;
}

void inserirDadosAluno(AnaliseAluno ** temp, char exercicio[40], int qntLinhas, int qntErros, Error erros[20])
{
	AnaliseAluno * add = addAnaliseAluno(exercicio, qntLinhas, qntErros, erros);

	if(*temp == NULL)
	{
		*temp = add;
	}
	else
	{
		AnaliseAluno * aux = *temp;

		if(!strcmp(aux->exercicio, add->exercicio))
		{
			add->proximo = aux->proximo;
			*temp = add;
			return;
		}		

		while(aux->proximo != NULL)
		{
			if(!strcmp(aux->proximo->exercicio, add->exercicio))
			{
				add->proximo = aux->proximo->proximo;
				aux->proximo = add;
				return;
			}
			aux = aux->proximo;
		}
		aux->proximo = add;
	}
}

void entradaArquivoAluno(char arq[40])
{
	char exercicio[40];
	int qntLinhas;
	int qntErros;
	Error erros[20];
	int i, j;
	FILE * file = fopen(arq, "r");
	if(file)
	{
		while(!feof(file))
		{
			fscanf(file, "%s %d %d\n", exercicio, &qntLinhas, &qntErros);
			for(j = 0; j < 20; j++)
			{
				fscanf(file," %s %d", erros[j].nome, &erros[j].qnt);
			}
			fscanf(file,"\n");
			inserirDadosAluno(&analiseAluno, exercicio, qntLinhas, qntErros, erros);
			
		}
		fclose(file);
	}
	else
	{
		analiseAluno = NULL;
	}
}

void saidaArquivoAluno(char arq[40])
{
	int j;
	FILE * file;
	AnaliseAluno * aux = analiseAluno;
	file = fopen(arq, "w+");

	while(aux != NULL)
	{
		fprintf(file, "%s %d %d\n", aux->exercicio, aux->qntLinhas, aux->qntErros);
		for(j = 0; j < 20; j++)
		{
			fprintf(file, " %s %d", aux->error[j].nome, aux->error[j].qnt);
		}
		fprintf(file, "\n");
		aux = aux->proximo;
	}

	fclose(file);
}

void imprimeAnaliseAluno(AnaliseAluno * temp)
{
	AnaliseAluno * aux = temp;

	while(aux != NULL)
	{
		printf("ex: %s\n", aux->nome);
		aux = aux->proximo;
	}
}



/*
* MECHENDO COM ANALISE DE DADOS
*/

typedef struct _AnaliseExercicio
{
	char nome[40];
	int nAlunos;
	int totalError;
	Error error[20];
	AnaliseAluno * aluno;
}AnaliseExercicio;

AnaliseExercicio analiseExercicio;
void analisaExercicio(char exercicio[40])
{
	char nome[40], nome2[40];
	char arq[40];
	char dirAlunos[40];
	int qntErros, qntLinhas, j;
	Error erros[20];
	DIR *d;
	struct dirent * pasta;

	strcpy(dirAlunos, "./alunos/");

	strcpy(analiseExercicio.nome, exercicio);
	analiseExercicio.nAlunos = 0;
	analiseExercicio.aluno == NULL;

	d = opendir(dirAlunos);
	if(d)
	{
		while((pasta = readdir(d)) != NULL)
		{
			if((strcmp(pasta->d_name, ".") && strcmp(pasta->d_name, "..")))
			{
				strcpy(nome, pasta->d_name);
				strcpy(arq, dirAlunos);
				strcat(arq, pasta->d_name);
				strcat(arq, "/");
				strcat(arq, nome);
				strcat(arq, ".txt");
				FILE * file = fopen(arq, "r");
				if(file)
				{
					while(!feof(file))
					{
						fscanf(file, "%s %d %d\n", nome2, &qntLinhas, &qntErros);
						for(j = 0; j < 20; j++)
						{
							fscanf(file," %s %d", erros[j].nome, &erros[j].qnt);
							strcpy(analiseExercicio.error[j].nome, erros[j].nome);
							
						}
						fscanf(file,"\n");
						if(!strcmp(analiseExercicio.nome,nome2))
						{
							AnaliseAluno * add = addAnaliseAluno(exercicio, qntLinhas, qntErros, erros);
							
							for(j = 0; j < 20; j++)
							{
								analiseExercicio.error[j].qnt += add->error[j].qnt;
								analiseExercicio.totalError += add->error[j].qnt;
								
							}
							strcpy(add->nome, nome);
							if(analiseExercicio.aluno == NULL)
							{
								analiseExercicio.aluno = add;
							}
							else
							{
								AnaliseAluno * aux = analiseExercicio.aluno;

								while(aux->proximo != NULL)
								{
									aux = aux->proximo;
								}
								aux->proximo = add;
							}
							analiseExercicio.nAlunos++;
						}
					}
					fclose(file);
				}
			}
		}
	}
	saidaArquivoExercicio();
}


void saidaArquivoExercicio()
{
	int i, j;
	char dirExercicios[40];
	char arq[40];
	strcpy(dirExercicios, "./exercicios/");
	strcpy(arq, dirExercicios);
	strcat(arq,analiseExercicio.nome);
	for(i = 5; arq[i] != '.'; i++);
		arq[i] = '\0';
	strcat(arq, ".txt");
	FILE * file = fopen(arq, "w");

	if(file)
	{
		fprintf(file, "%s %d %d\n", analiseExercicio.nome, analiseExercicio.nAlunos, analiseExercicio.totalError);
		for(i = 0; i < 20; i++)
		{
			fprintf(file, " %s %d", analiseExercicio.error[i].nome, analiseExercicio.error[i].qnt);
		}
		fprintf(file, "\n");
		AnaliseAluno * aux = analiseExercicio.aluno;

		for(j = 0; j < analiseExercicio.nAlunos; j++)
		{
			fprintf(file, "%s %d %d\n", aux->nome, aux->qntLinhas, aux->qntErros);
			for(i = 0; i < 20; i++)
			{
				fprintf(file, " %s %d", aux->error[i].nome, aux->error[i].qnt);
			}
			fprintf(file, "\n");
			aux = aux->proximo;
		}
		fclose(file);
	}
}