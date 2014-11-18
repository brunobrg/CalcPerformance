#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

extern int espacos;
extern int linhas_puladas;
extern int contadorDeLinhas;


void analise()
{
	if(espacos > 1)
		printf("--Linha: %d    Espacos: %d\n", contadorDeLinhas+1, espacos);

	espacos = 0;
}