#include <stdio.h>
#include <stdlib.h>

struct Emprego {
    int matricula;
    char nome[20];
    float salario;
};

struct Emprego E[5];

int menu(){
	int r;
	
	printf("CADASTRO DE EMPREGADOS\n\n");
	printf("1-Incluir\n");
	printf("2-Alterar\n");
	printf("3-Listar Todos\n");	
	printf("4-Sair\n\n");
	printf("Digite uma opcao : ");
	scanf("%d",&r);	
	
	return r;
}

void incluir(){
	int x;
	system("cls");
	for (x=0;x<5;x++){
		printf("Informe a matricula %d : ",x);
		scanf("%d",&E[x].matricula);
	
		printf("Informe o salario %d : ",x);
		scanf("%f",&E[x].salario);	

		printf("Informe o nome %d : ",x);
		scanf("%s",&E[x].nome);	
		system("cls");
	}
}

int alterar(){
	int x;
	system("cls");
	printf("Digite a posicao que deseja alterar: ");
	scanf("%d",&x);	

	if (x<0 || x>4){
		printf("Posicao invalida!\n\n");
		return -1;
	}
		
	printf("MATRICULA   SALARIO      NOME");
	printf("\n%5d \t %10.2f \t %s\n\n",E[x].matricula,E[x].salario,E[x].nome);
	
	printf("Informe a matricula %d : ",x);
	scanf("%d",&E[x].matricula);
	
	printf("Informe o salario %d : ",x);
	scanf("%f",&E[x].salario);	

	printf("Informe o nome %d : ",x);
	scanf("%s",&E[x].nome);	
	system("cls");
	return 0;
}

void listar(){
	
	int x;
	system("cls");
	printf("MATRICULA   SALARIO      NOME");
	for (x=0;x<5;x++){
		printf("\n%5d \t %10.2f \t %s",E[x].matricula,E[x].salario,E[x].nome);
	}
	printf("\n\n");
}

main() {
	int r; 

	r = menu();
	
	while (r>0 && r<4){
		if (r==1){
			incluir();
		}else if (r==2){
			alterar();
		}else if (r==3){
			listar();
		}
		r = menu();	
	}
}
