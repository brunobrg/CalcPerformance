/* sou foda */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Prototipos */

/* Variaveis Globais */

/* Main */
int main()
{
    float N1, N2, M;

    scanf("%f %f", &N1, &N2);
    M = ((N1 + N2) / 2);

    if (M < 3) {
        printf("REPROVADO");
    }

    if (M >= 7) {
        printf("APROVADO");
    }

    if (M >= 3 && M <7) {
        printf("EXAME");
    }

    return 0;
}

