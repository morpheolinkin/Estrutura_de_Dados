/*
MODELO DE MAIN PARA TRABALHAR COM LISTAS
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 0
#define false 1
#define TAM_LIST 10

// DECLARAR STRUCT 
typedef struct {
	int qtdElements;
	char atributo[TAM_LIST];
}nameStruct;


// DECLARA AS FUNCOES
// PASSAR STRUCT PARA AS FUNCOES
void startList(nameStruct *object);
void insertElementOnFinal(nameStruct *object);
void removeElementOnFinal(nameStruct *object);
void showAllElements(nameStruct *object);
void orderList(nameStruct *object);
void acessElementOnList(nameStruct *object);
int menu();
void exit();


//INICIA O CODE
main() {
	setlocale(LC_ALL,"portuguese_Brazil");
	menu();
}


// FUNCOES COMPLETAS
void startList(nameStruct *object) {
	object->qtdElements = 0;
}

void insertElementOnFinal(nameStruct *object) {
	char atributo;
	
	if(object->qtdElements > TAM_LIST - 1) {
		printf("ERROR 489 - LIST IS FULL!");
	} else {
		printf("Digite o novo elemento da lista: ");
		scanf(" %c",&atributo);	
		object->atributo[object->qtdElements] = atributo;
		object->qtdElements++;
		printf("elemento [ --> %c] inserido com sucesso! \n",atributo);
	}
}

void acessElementOnList(nameStruct *object) {
	int position;
	printf("Informe a posicao: ");
	scanf("%d",&position);
	
	if(position < 0 || position > object->qtdElements || object->qtdElements > TAM_LIST - 1) {
		printf("ERROR 586 - POSITION NOT EXIST IN LIST");
	} else {
		printf("| ---- EXIBINDO ELEMENTO. DA LISTA ---- | \n");
		printf("%c",object->atributo[position - 1]);
	}
}

void removeElementOnFinal(nameStruct *object) {
	if(object->qtdElements == 0) {
		printf("ERROR 986 - LIST NOT EXIST!");
	} else {
		object->qtdElements--;
	}
}
//asdasd
void showAllElements(nameStruct *object) {
	int tam;
	if(object->qtdElements == 0) {
		printf("ERROR 586 - LIST IS EMPTY");
	} else {
		printf("| ---- EXIBINDO ELEMENTOS DA LISTA ---- | \n");
		for(tam = 0; tam < object->qtdElements; tam++) {
			printf("%c",object->atributo[tam]);
		}
	}
}

void orderList(nameStruct *object) {
	
}

void exit() {
	
}


int menu() {

	nameStruct objeto;
	startList(&objeto);
	
  int op = -1;
  while (op != 0) {
        printf("\n#########################################################");
        printf("\n|                 AGENDA - MENU                         |");
        printf("\n|-------------------------------------------------------|");
        printf("\n|1 - INSERIR NO FINAL                                   |");
        printf("\n|2 - ACESSAR POSICAO NA LISTA                           |");
        printf("\n|3 - REMOVER ELEMENTO NO FINAL                          |");
        printf("\n|4 - MOSTRAR TODOS OS ELEMENTOS                         |");
        printf("\n|5 - IMPRIMIR AGENDA PARCIALMENTE                       |");
        printf("\n|6 - IMPRIMIR AGENDA COMPLETA                           |");
        printf("\n|7 - EXCLUIR CONTATO                                    |");
        printf("\n|0 - SAIR                                               |");
        printf("\n|-------------------------------------------------------|\n");

        scanf(" %d", &op);
        
        switch (op) {
            case 1:
                insertElementOnFinal(&objeto);
                break;
            case 2:
                acessElementOnList(&objeto);
                break;
            case 3:
                removeElementOnFinal(&objeto);
                break;
            case 4:
                showAllElements(&objeto);
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 0:
                return 0;
                break;
        }

    }
}
