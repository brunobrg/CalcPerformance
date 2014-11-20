#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

/* structs */
typedef struct _Error
{
	char nome[7];
	int qnt;
}Error;

/* variaveis globais */
extern int espacos;
extern int linhas_puladas;
extern int contadorDeLinhas;
extern int tab;
extern int OK;
int totalError;
Error error[20];

/* prototipos */
void inicializaAnalise();
void analise(int, int);
void addError(char[7]);

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
}

/* Funcoes das Analises */
void analise(int e, int l)
{
	char erro[7];

	if(espacos != e)
	{	
		strcpy(erro, "Error01");
		addError(erro);
		OK = 0;
		printf("Linha %d -- %s - Espacos necessarios: %d, Espacos utilizados: %d\n", contadorDeLinhas, erro, e, espacos);
	}
	if(linhas_puladas != l)
	{
		OK = 0;
		strcpy(erro, "Error02");
		addError(erro);
		printf("Linha %d --%s - Linhas necessarias: %d, Linhas utilizadas: %d\n", contadorDeLinhas , erro, l, linhas_puladas);
	}
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