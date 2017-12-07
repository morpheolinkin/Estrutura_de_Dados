#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define m 10

typedef struct{
    int comeco, fim;
    int matricula[m];
    float nota_trab[m];
    float nota_prova[m];
}fila;

void inicia (fila *F){
    F -> comeco = 0;
    F-> fim = -1;
}

void inserir (fila *F, int matri, float notaT, float notaP){
    if (F->fim ==m-1)
        printf("\aERRO 408, não há mais espaço pois a fila está cheia\n\n");
    else{
        F->fim++;
        F->matricula[F->fim] = matri;
        F->nota_trab[F->fim] = notaT;
        F->nota_prova[F->fim] = notaP;
    }
}

void remover (fila *F){
    if (F-> fim < F-> comeco)
        printf ("\aERRO 404, Fila vazia\n\n");
    else{
        F-> comeco++;
        printf("Pronto! removido\n");
    }
}

void primeiro (fila *F){
    int x;
    if (F->fim < F->comeco)
        printf("\aERRO 404, Fila Vazia\n\n");
    else{
        printf("Mostrando os alementos na primeira posição da Fila\n\n");
        printf (" Matricula -> Nº %d\n",F->matricula[F->comeco]);
        printf (" Nota do trabalho -> %.2f\n",F->nota_trab[F->comeco]);
        printf (" Nota da prova -> %.2f\n",F->nota_prova[F->comeco]);
    }
}

void exibir_fila (fila *F){
    int i;
	float SomaNota1, SomaNota2;
    float media;

    if (F-> fim < F-> comeco)
        printf ("\aERRO 404, Fila Vazia\n\n");
    else {

        //exibindo os valores
        for (i=F->comeco; i<=F->fim; i++){
            printf("\n=====================|\n");
            printf("%dº Aluno\n\n", i+1);
            printf("Matricula %d\n", F->matricula[i]);
            printf("Nota do trabalho %.2f\n", F->nota_trab[i]);
            printf("Nota da prova %.2f\n", F->nota_prova[i]);
            printf("\n=====================|\n\n");
            media = (F->nota_prova[i] + F->nota_trab[i])/2;
            if (media >=7){
                printf("*************************************************|\n");
            	printf("\nSua média foi %.2f e você foi aprovado, parabéns\n", media);
            	printf("*************************************************|\n\n");
            }
        	else
            {
                printf("*******************************************************************|\n");
            	printf("\nSua média foi %.2f, você está conservado, por favor estude mais!!\n", media);
                printf("\n*****************************************************************|\n\n");
            }
        }
	}
}

void maior_media (fila *F){
    int i, aux; //soma1 = 0, soma2 = 0, quant=0;
    float media, maiorMedia=0;

    if (F-> fim < F-> comeco)
        printf ("\aERRO 404, Fila Vazia\n\n");
    else {

    for (i=F->comeco; i<=F->fim; i++){
            media = (F->nota_prova[i] + F->nota_trab[i])/2;
            if (media > maiorMedia){
            	maiorMedia = media;
                aux = F->matricula[i];
            }
        }
        if (maiorMedia==maiorMedia)
                printf("O aluno de matricula %d é excelente nos estudos pois tem a maior média %.2f\n", aux, maiorMedia);
        printf("\n\n");
    }
	/*
    for(i=F->comeco; i<=F->fim; i++){
        if (media > maiorMedia){
            maiorMedia = F->matricula[i];
            printf("A matricula com a maior média é %d com média %.2f\n", maiorMedia, media);
        }
    }*/
}

/*
void falso_cheio_REORGANIZAR (struct fila *F){

    int x, com = F-> comeco, final = F-> fim;


    if (com > 0 && final == m-1){
        F-> comeco = 0;
        F-> fim = -1;
        for (x= com; x<=final; x++){
            F-> fim++;
            F-> elem[F-> fim] = F -> elem[x];
        }
    }else if (com==0) {
        printf ("Pilha esta normal");
    }
}
*/

int menu (){
        int r;
        printf("|==========================================|\n");
        printf("|\t     EDITOR DE FILA                |\n");
        printf("|==========================================|\n");
        printf("|1 - INSERIR                               |\n");
        printf("|2 - REMOVER                               |\n");
        printf("|3 - EXIBIR VALORES: MÉDIA NOTA E RESULTADO|\n");
        printf("|4 - MOSTRAR MATRICULA COM MAIOR MÉDIA     |\n");
        printf("|5 - MOSTRAR O PRIMEIRO ELEMENTO DA FILA   |\n");
        printf("|0 - SAIR                                  |\n");
        printf("|==========================================|\n");
        printf("\t     DIGITE SUA OPCAO: ");

        scanf("%d", &r);
        return r;
}


int main()
{
setlocale (LC_ALL, "");
    int r, dado1, y;
    float dado2, dado3;
    fila F;
    inicia(&F);

    r = menu();

    while (r!=0){
                if (r==1){
                    printf("\nInforme o código da matricula: ");
                    scanf("%d",&dado1);
                    printf("\nInforme a nota do trabalho: ");
                    scanf("%f",&dado2);
                    printf("\nInforme a nota da prova: ");
                    scanf("%f",&dado3);
                    inserir(&F,dado1, dado2, dado3);

                }else if (r==2){
                    remover(&F);
                }
                else if (r==3){
                    exibir_fila(&F);
                    //printf ("%d ", y);
                }
                else if (r==4){
                    maior_media(&F);
                }

                else if (r==5){
                    primeiro(&F);
                }
            printf("\n");
            system("pause");
            system ("cls");
            printf ("\n\n");
            r=menu();
    }
return 0;
}
