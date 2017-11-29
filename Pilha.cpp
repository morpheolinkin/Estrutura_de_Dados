#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
# define m 10

struct pilha {  	 // estrutura da pilha principal
	int topo;
	float elem[m];
};

///Funções para trabalhar com estrutura de PILHA
void inicializar_pilha (struct pilha *P);
void empilhar(struct pilha *P, float x);
void desempilhar(struct pilha *P);
void exibir_pilha (struct pilha *P);
void exibir_elemento_topo(struct pilha *P);
void esvaziar_pilha (struct pilha *P);
void localizar_noh(struct pilha *P, float x);
void mostrar_valor_noh(struct pilha *P, int n);
void elementos_pares(struct pilha *P);
void maior_menor(struct pilha *P);
void pilha_ordenada(struct pilha *P);


int menu (){
	int r;

	printf("|=======================================================|\n");
	printf("|                EDITOR DE PILHA                        |\n");
	printf("|                                                       |\n");
	printf("|         1 - EMPILHAR                                  |\n");
	printf("|         2 - DESEMPILHAR                               |\n");
	printf("|         3 - EXIBIR ELEMENTO DO TOPO                   |\n");
	printf("|         4 - EXIBIR A PILHA                            |\n");
	printf("|         5 - ESVAZIAR A PILHA                          |\n");
	printf("|         6 - MOSTRAR NÓ DE DETERMINADO VALOR           |\n");
	printf("|         7 - MOSTRAR O VALOR DE DETERMINADO NÓ         |\n");
	printf("|         8 - MOSTRAR OS ÍNDICES PARES DA PILHA         |\n");
	printf("|         9 - MOSTRAR O MAIOR E MENOR VALOR DA PILHA    |\n");
	printf("|         10 - ORDENAR PILHA DE FORMA CRESCENTE         |\n");
	printf("|         11 - SAIR                                     |\n");
	printf("|=======================================================|\n");
	printf("\n         DIGITE SUA OPCAO:  ");
	scanf("%d",&r);
	return r;
}

//Fução principal
int main (){
///Função para eceitar os caracteres no idioma padrão do sistema.
setlocale(LC_ALL, "");

	int r, n, i;
	float x;
	float dado;
	struct pilha P;
	///Deve primeiro inicialiar a pilha
	inicializar_pilha(&P);

    ///Chama o menu
	r=menu();

	while (r!=11){
		if (r==1){
			printf("\n Informe o valor para inclusão: ");
			scanf("%f",&dado);
			empilhar(&P,dado);

		}else if (r==2){
			desempilhar (&P);
		}
		else if (r==3){
			exibir_elemento_topo(&P);
		}
		else if (r==4){
			exibir_pilha (&P);
		}
		else if (r==5){
			esvaziar_pilha(&P);
		}
		else if (r==6){
			localizar_noh(&P,x);
		}
		else if (r==7){
			mostrar_valor_noh (&P,n);
		}
		else if (r==8){
			elementos_pares (&P);
		}
		else if (r==9){
			maior_menor (&P);
		}
		else if (r==10){
			printf ("Em ordem crecente\n");
			pilha_ordenada (&P);
		}

		printf("\n");
		system ("pause");
		system ("cls");
		printf("\n");
		r=menu();

    }
return 0;
}


// inicializar a pilha
void inicializar_pilha (struct pilha *P){ //"pilha" é o nome da estrutura e "P" o ponteiro
	P-> topo = -1; 		// é -1 porque somara mais um e inicia no índice 0
}



 void empilhar (struct pilha *P, float x) { // recebe a pilha e o valor a ser empilhado
 	if (P->topo == m-1)	{    // vai de 0 a 9 = 10 definido
	 	printf ("\a\aPAM!! Erro 666 DO DIABO, sua pilha está CHEIA\n");
	  }  // se estiver espaço na pilha pode acrescentar elemento
 	else {
 		P->topo ++;   // tem espaço na pilha pode atribuir elemento
 		P->elem [P->topo]=x;  // x é o elemento na posição do topo se não tiver cheio
	 }
 }

 void desempilhar (struct pilha *P){
 	if (P-> topo == -1)	// se o topo estiver vazio não tem o que tirar
 	printf ("\a\aPAM!! Erro 666 DO DIABO, sua pilha está VAZIA\n");
 	else {
 		P->topo --; // se tiver cheia retira o último elemento (desmpilha)
	 }
 }

 void exibir_pilha (struct pilha *P){
 	int i;
 	if (P-> topo == -1) // pilha vazia
 	printf ("\a\aPAM!! Erro 666 do diabo, sua pilha está vazia\n");
 	else {
 		printf ("Os elementos da pilha: ");

 		for (i=0; i<=P->topo; i++){
 			printf (" %.2f  ", P->elem[i]);
		 }

	 }
 }

 void exibir_elemento_topo (struct pilha *P){

 	if (P-> topo == -1) // pilha vazia
 	printf ("\a\aPAM!! Erro 666 DO DIABO, sua pilha está vazia\n");
 	else {
 		printf ("A nota localizada no topo: %.2f \n ", P->elem[P->topo]);
		 }

	 }

 void esvaziar_pilha (struct pilha *P){
 	P-> topo = -1;   // topo recebe -1 (inicializa e fica vazia)

 	printf("\a\aUFAA!! Pilha Esvaziada!! Que alívio.");
 }

 void localizar_noh (struct pilha *P, float x){ //Localizar a posição que está determinado valor

	 	int i;

        printf ("digite a nota para saber a posição: ");
 		scanf ("%f",&x);

 		if (P-> topo == -1) // pilha vazia
 		printf ("\a\aPAM!! Erro 666 DO DIABO! - Esta posição não existe ainda.\n");

 		else{
 			for (i=0; i<=P->topo; i++){
                if (x==P->elem[i])
                    printf ("O valor informado está na posição: %d \n",i);

		 	}
		 }

}

///Localizar o valor que está em determinada posição
 void mostrar_valor_noh (struct pilha *P, int n){

    int i;

    printf ("digite a posição para saber a nota: ");
    scanf ("%d",&n);

    if (P-> topo == -1 || n < 0 || n > P->topo || P->topo > m - 1) // pilha vazia
 		printf ("\a\aPAM!! Erro 666 DO DIABO! - Este valor não está localizado em nenhuma posição da pilha\n");

    else{
        for (i=0; i<=P->topo; i++){
 			if (n==i)
 				printf (" A nota da posição informada: %.2f\n ",P->elem[i]);

		 	}
		 }

}

///Mostra as posições pares, não deu certo mostrar os valores pares porque estamos trabalhando com tipo float na
///variável elem da struct pilha
void elementos_pares (struct pilha *P){

        int i, par=0;
        if (P->topo == -1) // pilha vazia
	 	printf ("PAM!! Erro 666 do diabo, sua pilha está vazia\n");


	 	for (i=0; i<=P->topo; i++){///Professor pedio para mostrar os elementos pares, mas como float não tem como mostrar
                ///foi alterado para os índices pares.
	 		if (i%2==0){
			 	par=i;
	 			printf ("Os índices pares são: %d\n", par);
	 		}
		 }

}

///Mostra o maior e o menor valor na pilha.
void maior_menor (struct pilha *P){
    int i;
    float maior, menor;

    if (P->topo==-1)
	 	printf ("PAM!! Erro 666 do diabo, sua pilha está vazia\n");

    for (i=-1; i<=P->topo;i++){// Para não carregar o lixo da memoria, atribuí no primeiro laço o valor para o MAIOR E MENOR.
        if (i==0)	{
            maior = P->elem[i];// Aqui quando i==0 o primeiro valor vai para maior
            menor = P->elem[i];// Aqui quando i==0 o primeiro valor vai para menor
        }

        if (P->elem[i]>maior){ // Aqui é feito um teste para saber se o valor é maior que o primeiro valor na posição atual
            maior = P->elem[i];// Se for maior atribui esse valor para a variavel maior
        }
        else if (P->elem[i] < menor){
            menor = P->elem[i]; //Se não for maior, lógico que ele é o menor, então atribui a variável menor
        }
    }

        printf ("O maior elemento eh %.2f e o menor %.2f\n", maior, menor);
}


///Função para ordenar a pilha
void pilha_ordenada(struct pilha *P) {
    float temp; //Variável auxiliar para armazenar os valores de P->elem[lin]
    int lin, col, num;

    for(lin = 0; lin <=P->topo; lin++) {
    	for(col = lin; col <=P->topo; col++) {
    		if(P->elem[lin] > P->elem[col]) { //Aqui verifica se o valor na linha é maior que o da coluna
				temp = P->elem[lin]; //Se não for, atribui o valor da linha a variável TEMP
				P->elem[lin] = P->elem[col]; //Aqui puxo o valor da coluna para a linha.
				P->elem[col] = temp; //O valor que estava armazenado em TEMP que era da linha vai para coluna
				//Para quando a linha não for maior que a coluna, neste caso os valores estaram ordenados.
			}
		}
	}
    ///Para exibir os valores já ordenados. Poderia também só chamar a funcão exibir_pilha (P) que também daria certo
    ///já que os valores já estão armazenado na memoria de forma ordenada.
    for(num = 0; num <=P->topo; num++) {
		printf("%.2f ",P->elem[num]);

    }
}
