/* programa_matriz_01.c */

#include<stdio.h>
#include<stdlib.h>
#define DIMENSAO 2

int main(void){
    int linha, coluna;
    int determinante;
    int valorA;
    int matriz [DIMENSAO][DIMENSAO];

    /* Uma regra que se pode sempre levar em consideração:
    para cada dimensão de uma matriz, sempre haverá um laço
    (normalmente um for). Se houver duas dimensões, então haverá dois laços. */

    for (linha = 0; linha < DIMENSAO; linha++){
        for (coluna = 0; coluna < DIMENSAO; coluna++){
            printf ("Entre item %d %d: ", linha + 1, coluna + 1);
            scanf ("%d", &valorA);
            matriz [linha][coluna] = valorA;
        }
        printf("\n");
    }

    determinante = matriz[0][0] * matriz [1][1] -
    matriz[0][1] * matriz [1][0];
    printf ("Determinante : %d\n", determinante);

    return 0;
}
