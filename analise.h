#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

extern int espacos;
extern int linhas_puladas;
extern int contadorDeLinhas;
extern int tab;
//prototipos
void inicializaAnalise();
void analise(int, int);


void inicializaAnalise()
{
	espacos = 0;
	linhas_puladas = 0;
}

void analise(int e, int l)
{
	if(espacos != e)
	{	
		printf("--ERRO1, Linha: %d, Espacos necessarios: %d, Espacos utilizados: %d\n", contadorDeLinhas, e, espacos);
	}
	if(linhas_puladas != l)
	{
		printf("--ERRO2, Linha: %d, Linhas necessarias: %d, Linhas utilizadas: %d\n", contadorDeLinhas, l, linhas_puladas);
	}
	linhas_puladas = 0;
	espacos = 0;
}

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