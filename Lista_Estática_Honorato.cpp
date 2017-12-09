#include <stdio.h>
#include <stdlib.h>
#define m 10

struct Lista {
	int n;
	int mat[m];
	float nota[m];
};

void inicialista(struct Lista *L){
	L->n = 0;
}

void inserirFinal(struct Lista *L, int mat, float nota){
	if (L->n > m-1)
		printf("Lista cheia");
	else{
		L->mat[L->n] = mat;
		L->nota[L->n] = nota;
		L->n++;
	}
}

void localizarMat(struct Lista *L,int mat){
	int x;
	if (L->n == 0)
		printf("Lista vazia!");
	else{
		system("cls");
		for (x=0;x<L->n;x++)
			if (mat==L->mat[x]) 
				printf("Matricula lozalizada na posicao %d",x);		
	}
}

void exibir(struct Lista *L){
	int x;
	if (L->n == 0)
		printf("Lista vazia!");
	else{
		system("cls");
		printf("\nELEMENTOS DA LISTA:\n");
		for (x=0;x<L->n;x++)
			printf("%d\t%f\n ",L->mat[x],L->nota[x]);		
		printf("\n\n");
	}
}

void subLista(struct Lista *L, struct Lista *SL){
	int x;
	inicialista(SL);
	if (L->n == 0)
		printf("Lista vazia!");
	else{
		system("cls");
		for (x=0;x<L->n;x++)
			if (L->nota[x]>7)
				inserirFinal(SL,L->mat[x],L->nota[x]);		
		exibir(SL);
	}
}

void removerFinal(struct Lista *L){
	if (L->n == 0)
		printf("Lista vazia!");
	else{
		L->n--;
	}
}

void removerK(struct Lista *L, int k){
	if ((k < 0 || k> (L->n-1)) || (L->n > m-1))
		printf("erro – elemento fora dos limites\n");
	else{
		int x;
		for (x=k;x<L->n;x++){
			L->mat[x]=L->mat[x+1];
			L->nota[x]=L->nota[x+1];
		}
		L->n--;
	}
}

void inserirK(struct Lista *L, int k){
	if ((k < 0 || k> (L->n-1)) || (L->n > m-1))
		printf("erro – elemento fora dos limites\n");
	else{
		int x;
		for (x=L->n-1;x>k;x--){			
			L->mat[x+1]=L->mat[x];
			L->nota[x+1]=L->nota[x];
		}
		L->mat[k+1]= 1000;
		L->nota[k+1]= 10;
		L->n++;
	}
}

void acessar(struct Lista *L, int k){
	char dado;
	if ((k < 0 || k> (L->n-1)) || (L->n > m-1))
		printf("erro – elemento fora dos limites\n");
	else{
		dado = L->mat[k];
		printf("\n%c\n", dado);
	}
}

int menu (){
	int r;
	
	printf("EDITOR DE LISTA\n\n");

	printf("1 - INSERIR NO FINAL\n");
	printf("2 - DETERMINAR O NUMERO DE NOS DE UMA LISTA\n");
	printf("3 - EXIBIR ELEMENTOS\n");
	printf("5 - EXCLUIR K\n");
	printf("9 - SUB LISTA k\n");
	printf("6 - SAIR\n\n"); 

	printf("DIGITE SUA OPCAO: ");
	scanf("%d",&r);
	return r;
}

main(){
	int r, mat;
	float nota;
	struct Lista L, SL;
	inicialista(&L);
	
	r=menu();

	while (r!=6){
		if (r==1){
			printf("Informe a matricula para inclusao: ");
			scanf("%d",&mat);
			printf("Informe a nota: ");
			scanf("%f",&nota);
			inserirFinal(&L,mat,nota);
			system("cls");			
		}else if (r==2){
			system("cls");
			printf("A lista possui %d elementos.\n\n",L.n);
			//removerFinal(&L);
		}else if (r==3){
			exibir(&L);
		}else if (r==5){
			int k;
			printf("Informe a posicao para excluir: ");
			scanf("%d",&k);
			
			removerK(&L,k);
		}else if (r==9){
			subLista(&L,&SL);
		}else if (r==5){
			int k;
			system("cls");			
			printf("Informe o k para consulta : ");
			scanf("%d",&k);
			acessar(&L,k);
		}else if (r==7){
			int k;
			system("cls");			
			printf("Informe o k para inserir : ");
			scanf("%d",&k);
			inserirK(&L,k);
		}
		
		r=menu();
	}
}
