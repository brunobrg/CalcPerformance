#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/* structs */
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

typedef struct _SaidaAnalise
{
	char erro[7];
    int contL;
    int nec;
    int uti;
    struct _SaidaAnalise * proximo;
}SaidaAnalise;

/* variaveis globais */
extern int espacos;
extern int linhas_puladas;
extern int contadorDeLinhas;
extern int tab;
extern int OK;
extern int contadorEspacos;
extern int usouTab;
extern Comment comment_criador, comment_prototipo, comment_include, comment_main, comment_funcoes, comment_vglobais;

int totalError;
Error error[20];
SaidaAnalise * saidaAna;


/* prototipos */
void inicializaAnalise();
void analise(int, int);
void addError(char[7]);
void inserirSaidaAnalise(int, char[], int, int);
SaidaAnalise * addSaidaAnalise(int, char[], int, int);
void imprimeAnalise();

void inicializaAnalise()
{
	int i;

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
	if(l > 0 && linhas_puladas != l)
	{
		OK = 0;
		strcpy(erro, "Error02");
		addError(erro);
		inserirSaidaAnalise(contadorDeLinhas, erro, l, linhas_puladas);
		//printf("Linha %d --%s - Linhas necessarias: %d, Linhas utilizadas: %d\n", contadorDeLinhas , erro, l, linhas_puladas);
	}
	else if(usouTab)
	{
		OK = 0;
		inserirSaidaAnalise(contadorDeLinhas, "Error03", 0, 0); 
		addError("Error03");
	}
	else if(espacos != e && usouTab == 0)
	{	
		strcpy(erro, "Error01");
		addError(erro);
		OK = 0;
		inserirSaidaAnalise(contadorDeLinhas, erro, e, espacos);
		//printf("Linha %d -- %s - Espacos necessarios: %d, Espacos utilizados: %d\n", contadorDeLinhas, erro, e, espacos);
		
	}
	usouTab = 0;
	linhas_puladas = 0;
	espacos = 0;
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

SaidaAnalise * addSaidaAnalise(int contL, char erro[7], int nec, int uti)
{
    SaidaAnalise * add = (SaidaAnalise*) malloc(sizeof(SaidaAnalise));
    strcpy(add->erro, erro);
    add->contL = contL;
    add->nec = nec;
    add->uti = uti;
    add->proximo == NULL;

    return add;
}

void inserirSaidaAnalise(int contL, char erro[7], int nec, int uti)
{
	SaidaAnalise * aux = addSaidaAnalise(contL, erro, nec, uti);

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
			printf("Linha %d -- %s - Espacos necessarios: %d, Espacos utilizados: %d\n", aux->contL, aux->erro, aux->nec, aux->uti);
		}
		else if(!(strcmp(aux->erro, "Error02")))
		{
			printf("Linha %d -- %s - Linhas necessarias: %d, Linhas utilizadas: %d\n", aux->contL, aux->erro, aux->nec, aux->uti);
		}
		else if(!(strcmp(aux->erro, "Error03")))
		{
			printf("Linha %d -- %s - Nao utilizar tabulacoes\n", aux->contL, aux->erro);
		}
		aux = aux->proximo;
	}

}