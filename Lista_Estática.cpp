/*	

	ESTRUTURA DE DADOS
	GUSTAVO RODRIGUES FERNANDES DA SILVA
	LCC 2017.1
PARA PILHA

L->TOPO=-1

P->TOPO++;
P->elem[P->TOPO]=x
*/


#include <stdio.h>
#include <stdlib.h>
#define m 10

struct lista {
	int n;
	int mat[m];
	float nota[m];
};

int m_no=m;

void inicia_lista (struct lista *L){ //INICIAR LISTA
	L->n=0;
}

void inserir_final (struct lista *L){  // 1 - INSERIR NÓ NO FINAL
	
	if (L->n > m_no-1)
		printf("erro - elemento fora dos limites\n\n");
	else{
		
		printf ("DIGITE A MATRICULA: ");
		scanf ("%d", &L->mat[L->n]);
		printf("\n");
		printf ("DIGITE A NOTA: ");
		scanf ("%f", &L->nota[L->n]);
		printf("\n");
		L->n++;
	}	
		system("pause");
		system("cls");
	}

void posicao (struct lista *L){  // 3 - ACESSAR NÓ ESPECÍFICO
	
	int ler_user;

	printf ("DIGITE A MATRICULA: ");
	scanf ("%d", &ler_user);

		for(L->n = 0; L->n <= m_no; L->n++){
			if (ler_user==L->mat[L->n]){
				printf ("\nA MATRICULA %d ESTA NA POSICAO %d.\n", L->mat[L->n], L->n+1);
			}
		}
	system("pause");
	system("cls");
}

void acessar_matricula (struct lista *L, int k){  // 4 - MOSTRAR O VALOR DE UM DETERMINADO

	int ler_user;
	k=m_no;

	printf ("DIGITE A POSICAO: ");
	scanf ("%d", &ler_user);

		for(L->n = 0; L->n <= k; L->n++){
			if (ler_user==(L->n+1)){
				printf ("\nA MATRICULA 'E %d:\n", L->mat[L->n]);
				printf ("A NOTA 'E %0.2f:\n", L->nota[L->n]);
			}
		}
	system("pause");
	system("cls");
	k=m_no;
}

void remover (struct lista *L){	// 5 - EXCLUIR UM K_ESIMO NO' DA LISTA
	
	int ler_user, i;
	int mat_alt;
	float nota_alt;

	printf ("DIGITE A POSICAO: ");
	scanf ("%d", &ler_user); 
	ler_user=ler_user-1;
	
	if ((ler_user<0) || (ler_user> m_no) ){
		printf("\nERRO! POSICAO FORA DOS LIMITES!\n");
		system ("pause");
	}else
		mat_alt=L->mat[m_no-1];
		nota_alt=L->nota[m_no-1];
		
		L->mat[m_no-1]=L->mat[ler_user];
		L->nota[m_no-1]=L->nota[ler_user];
		
		L->mat[ler_user]=mat_alt;
		L->nota[ler_user]=nota_alt;
		
	m_no--;
}

void maior (struct lista *L){	// 6 - MOSTRAR A MAIOR NOTA DA LISTA E O NUMERO DA MATRICULA DO ALUNO
	
	int maior_mat; 
	float maior_nota;
	
	maior_nota = L->nota[L->n];
	maior_mat = L->mat[L->n];
	
	for (L->n = 0; L->n <m_no; L->n++){
		if (L->nota[L->n] > maior_nota){
			maior_nota = L->nota[L->n];
			maior_mat = L->mat[L->n];
		}
	}
	printf ("\nA MATRICULA %d TEM MAIOR NOTA ENTRE TODAS, QUE 'E %0.2f.\n\n", maior_mat, maior_nota);
	system("pause");
	system("cls");
	
}	
		
void imprimi (struct lista *L){	// 10 - MOSTRAR TODOS OS ELEMENTOS DA LISTA
	
	printf("LISTA DE MATRICULAS E NOTAS:\n====================\n");
	for(L->n = 0; L->n < m_no; L->n++){
		
		printf("\nPOSICAO %d \n\n", L->n+1);
		printf("Matricula: %d \n", L->mat[L->n]);
		printf("Nota: %0.2f \n", L->nota[L->n]);
		printf("====================\n");
		
	}
		system ("pause");
		system("cls");
		printf("\n\n");
		
}

void sublista (struct lista *L, struct lista *L2){	//	9 - GERAR SUBCADEIA
	int x;
	inicia_lista(L2);
	if (L->n==0)
		printf ("LISTA VAZIA\n\n");
	else{
		for (x=0; x<L->n; x++){
			if (L->nota[x]>=7){
				L2->mat[x]=L->mat[x];
				L2->nota[x]=L->nota[x];
				printf("\nAPROVADOS:\n\n");
				printf("\nPOSICAO %d \n\n", x+1);
				printf("Matricula: %d \n", L2->mat[x]);
				printf("Nota: %0.2f \n", L2->nota[x]);
				printf("====================\n");
			}		
		}
		system ("pause");
		system("cls");
	}
}
		
int menu(){

	int tecla;
	
	printf ("0 - SAIR\n");	//
	printf ("1 - INSERIR MATRICULAS E NOTAS NO FINAL DA LISTA\n");	//
	printf ("2 - DETERMINAR O NUMERO DE MATRICULAS E NOTAS DA LISTA\n");	//
	printf ("3 - MOSTRAR A POSICAO DA MATRICULA E NOTA\n");	//
	printf ("4 - LOCALIZAR DETERMINADA MATRICULA E NOTA\n");	//
	printf ("5 - EXCLUIR UMA MATRICULA E NOTA DA LISTA\n");
	printf ("6 - MOSTRAR A MAIOR NOTA DA LISTA E O NUMERO DA MATRICULA DO ALUNO \n"); //
	printf ("7 - INSERIR UMA NOVA MATRICULA E NOTA APOS UMA ESPECIFICA\n");
	printf ("8 - ORDENAR A LISTA\n");
	printf ("9 - GERAR SUBCADEIA SOMENTE COM ALUNOS APROVADOS E MOSTRA-LA\n"); //
	printf ("10 - MOSTRAR TODOS OS ELEMENTOS DA LISTA\n\n");	//
	printf ("DIGITE SUA OPCAO:\n\n");
	scanf ("%d", &tecla);
	system ("cls");
	return tecla;
	
}

main(){
	
	int r, ler_numero_no, cont;
	int matricula;
	float nota;
	r=menu();
	
	struct lista l;
	struct lista l2;
	inicia_lista (&l);
	
	while (r!=0){
		if (r==1){
			inserir_final (&l);
			r=menu();
			
			
		}else if (r==2){
			printf ("DIGITE O LIMITE DE NOS: ");
			scanf ("%d", &ler_numero_no);
			m_no=ler_numero_no;							//	2 - DETERMINAR O NUMERO DE NOS DE UMA LISTA
			printf ("\n\n");
			r=menu();
			
		}else if (r==3){
			posicao (&l);
			r=menu();
			
		}else if (r==4){
			acessar_matricula (&l, cont);
			r=menu();
		
		}else if (r==10){
			imprimi (&l);
			r=menu();
			
		}else if (r==5){
			remover (&l);
			r=menu();
		
		}else if (r==6){
			maior (&l);
			r=menu();
		
		}
		
		else if (r==9){
			sublista (&l, &l2);
			r=menu();
		
		}
	
	}
}
