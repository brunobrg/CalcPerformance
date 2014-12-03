#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 100

/* structs */
struct stat st = {0};

typedef struct _Comment
{
	int existe;
	int possui;
}Comment;

typedef struct _Error
{
	char nome[7];
	int qnt;
}Error;

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
extern int tab;
extern int OK;
extern int contadorEspacos;
extern int usouTab;
extern Comment comment_criador, comment_prototipo, comment_include, comment_main, comment_funcoes, comment_vglobais;
extern FILE * yyin;

int totalError;
Error error[20];
SaidaAnalise * saidaAna;
SaidaError * saidaError;
Variaveis * varDeclaradas;
Variaveis * varUsadas;

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

void inicializaAnalise()
{
	int i;

	varDeclaradas = NULL;
	varUsadas = NULL;
	saidaError = NULL;
	espacos = 0;
	linhas_puladas = 0;
	totalError = 0;
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
		printf("entrou tab");
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
			printf("Linha %d:%d -- %s - Espacos necessarios: %d, Espacos utilizados: %d\n", aux->contL, aux->contE, aux->erro, aux->nec, aux->uti);
		}
		else if(!(strcmp(aux->erro, "Error02")))
		{
			printf("Linha %d:%d -- %s - Linhas necessarias: %d, Linhas utilizadas: %d\n", aux->contL, aux->contE, aux->erro, aux->nec, aux->uti);
		}
		else if(!(strcmp(aux->erro, "Error03")))
		{
			printf("Linha %d:%d -- %s - Nao utilizar tabulacoes\n", aux->contL, aux->contE, aux->erro);
		}
		else if(!(strcmp(aux->erro, "Error04")))
		{
			printf("Linha %d:%d -- %s - Declaracao da variavel \"%s\" nao se encontra no inicio do bloco.\n", aux->contL, aux->contE, aux->erro, aux->strAux);
		}
		else if(!(strcmp(aux->erro, "Error10")))
		{
			printf("Linha %d:%d -- %s - Variavel \"%s\" declarada nao utilizada.\n", aux->contL, aux->contE, aux->erro, aux->strAux);
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

void inicio()
{
	char arq[20];
	char arq2[20];
	char aluno[30];
	char dir[30];
	int result;

	strcpy(dir, "../CalcPerformance/");
	//Lendo arquivos
	printf("aluno: ");
	scanf("%s", aluno);

	strcat(dir, aluno);
	printf("%s\n", dir);
	if(stat(dir, &st) == -1)
	{
		mkdir(dir, 0777);
	}

	printf("arquivo: ");
	scanf("%s", arq);

	strcat(dir, "/");
	strcpy(arq2, dir);
	strcat(arq2, arq);
	FILE * myfile = fopen(arq2, "r");
	if(!myfile)
	{
		myfile = fopen(arq, "r");
		if(!myfile)
		{
			printf("\nArquivo nao encontrado. Abortando...\n");
			scanf("%*c");
			exit(1);
		}
		rename(arq, arq2);
	}

	yyin = myfile;
}