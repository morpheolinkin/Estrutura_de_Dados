#include<stdio.h>
#define TAMANHO 5

int main(void){
    int iIndice;
    int iValorA;
    int iSoma;
    int aVetor [TAMANHO];
    float fMedia;

    for (iIndice=0; iIndice<TAMANHO;iIndice++){
        printf("Entre com o valor %d: ", iIndice+1);
        scanf("%d", &iValorA);
        aVetor[iIndice] = iValorA;
    }

    iSoma = 0;

    for (iIndice = 0; iIndice < TAMANHO; iIndice++){
        iSoma += aVetor[iIndice];
    }
    printf("\n");
    fMedia = (float) iSoma / TAMANHO;
    printf("Media: %.2f\n", fMedia);
    printf("A soma eh: %d", iSoma);
    return 0;
}
