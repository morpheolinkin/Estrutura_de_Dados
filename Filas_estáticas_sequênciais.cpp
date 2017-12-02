/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define m 10
struct fila{
    int comeco, fim;
    int elem[m];
};


void inicia (struct fila *F){
    F -> comeco = 0;
    F-> fim = -1;
}

void inserir (struct fila *F, int x ){
    if (F->fim ==m-1)
        printf("Fila Cheia");
    else{
        F->fim++;
        F->elem[F->fim]=x;
    }
}

void remover (struct fila *F){
    if (F-> fim < F-> comeco)
        printf ("Fila vazia");
    else
        F-> comeco++;
}

int primeiro (struct fila *F){
    int x;
    if (F->fim < F->comeco)
        printf("Fila Vazia");
    else{
        x = F->elem[F->comeco];
    return(x);
    }
}

void mostrar_tudo (struct fila *F){
    int i;
    
    if (F-> fim < F-> comeco)
        printf ("Fila Vazia");
    else {
        for (i=F->comeco; i<=F->fim; i++){
            printf("%d ", F->elem[i]);
        }
    }
    printf("\n");
}

int menu (){
        int r;
        printf("|==============================|\n");
        printf("|\tEDITOR DE LISTA             |\n");
        printf("|==============================|\n");
        printf("|1 - INSERIR                   |\n");
        printf("|2 - REMOVER                   |\n");
        printf("|3 - EXIBIR VALOR DO INICIO    |\n");
        printf("|4 - EXIBIR A FILA             |\n");
        printf("|5 - ESVAZIAR A FILA           |\n");
        printf("|6 - SAIR                      |\n");
        printf ("==============================|\n");
        printf("\t DIGITE SUA OPCAO: ");

        scanf("%d", &r);
        return r;
}


int main()
{
    int r, dado, y; 
    struct fila F;
    inicia(&F);
    
    r = menu();
    
    while (r!=6){
                if (r==1){
                    printf("\nInforme o valor para inclusao: ");
                    scanf("%d",&dado);
                    inserir(&F,dado);

                }else if (r==2){
                    remover(&F);
                }
                else if (r==3){
                    y = primeiro(&F);
                    printf ("%d ", y);
                }
                else if (r==4){
                    mostrar_tudo(&F);
                    
                }
                else if (r==5){
                    inicia(&F);
                }
            system("pause");       
            system ("cls");
            printf ("\n\n");
            r=menu();
    
    
    }
return 0;
}
