# Estrutura_de_Dados
Atividades desenvolvidas durante a disciplina de Estrutura de Dados com o professor Honorato, IF Senhor do Bonfim


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

typedef struct {
    char nome[30];
    int idade;
}CLIENTE;

typedef struct{
    CLIENTE vetor[MAX];
    int nElem;
}LISTA;

void criar_Lista(LISTA *L){
    L -> nElem = 0;
}

void inserir_Final (LISTA *L, CLIENTE c1){
    L -> vetor[L -> nElem] = c1;
    L -> nElem = L-> nElem+1;

}

void Inserir_Posicao(LISTA *L, int pos, CLIENTE c1){
    int i;
    if (pos > L ->nElem)
        inserir_Final(L, c1);
    else
    {
     for  (i=L->nElem; i > pos; i++){
        L->vetor[i] = L->vetor[i-1];
     }
     L->vetor[pos] = c1;
     L->nElem = L->nElem + 1;
    }
}

void inserir_Inicio (LISTA *L, CLIENTE c1){
    Inserir_Posicao(L, 0, c1);
}

CLIENTE *Acessar_A_Partir_do_Inicio(LISTA *L, int pos){
    if (pos < L->nElem)
        return &L->vetor[pos];
    else
        return NULL; ///Não encontrou.
}

CLIENTE *Acessar_A_Partir_do_Fim(LISTA *L, int pos){

    if (pos < L->nElem)
        return &L->vetor[L->nElem-pos-1];
    else
        return NULL; ///Não encontrou.
}

void listar_Inicio_ao_Fim(LISTA *L){
    int i;
    CLIENTE c1;
    for (i=0; i<L->nElem; i++){
        c1 = L->vetor[i];
        printf("Nome: %s\n", c1.nome);
        printf("Idade: %d\n\n", c1.idade);
    }
}

void listar_Fim_ao_Inicio(LISTA *L){
/*O que muda aqui é que ao invés da posição 'i' começar do inicio que é 0
vai começar do final que é a quantidade de elementos (L->nlem) retirando um a cada ciclo. (-- na posição).
*/
///O número de elementos ele indica uma posição a mais, então tem de começar a listar do ultimo menos 1
/// então do L-> nElem -1;

    int i;
    CLIENTE c1;
    for (i=L->nElem-1; i>=0; i--){
        c1 = L->vetor[i];
        printf("Nome: %s\n", c1.nome);
        printf("Idade: %d\n\n", c1.idade);
    }
}

void Eliminar_Posicao(LISTA *L, int pos){
    int i;
    if (pos < L->nElem){
        if (pos == L->nElem - 1){
            L->nElem = L->nElem - 1;
        }
        else {
            for (i=pos; i<L->nElem-1; i++){
                L->vetor[i] = L->vetor[i+1];
            }
            L->nElem = L->nElem - 1;
        }
    }
}

CLIENTE *Buscar_Endereco_por_Nome (char nome[], LISTA *L){
    int i;
    for (i=L->nElem-1; i>=0; i--){
        if (strcmp(nome, L->vetor[i].nome)==0)
            return &L->vetor[i];
    }
    return NULL;
}

int Buscar_posicao_por_Nome (char nome[], LISTA *L){
    int i;
    for (i=L->nElem-1; i>=0; i--){
        if (strcmp(nome, L->vetor[i].nome)==0)
            return i;
    }
    return -1;
}


int Tamanho_da_Lista(LISTA L){/// Aqui é só retornar o núemro de elementos da lista.
    return L.nElem;
}

void destruir_Lista(LISTA *L){///Aqui é só atribuir 0 ao numero de elmentos da lista.
    L->nElem = 0;
}


int menu_da_Lista (){
    int escolha;
printf("========================================================\n");
        printf("1 - Criar Listas\n");
        printf("2 - Inserir Inicio\n");
        printf("3 - Inserir Final\n");
        printf("4 - Inserir Posicao\n");
        printf("5 - Acessar a partir do Inicio\n");
        printf("6 - Acessar a partir do Fim\n");
        printf("7 - Listar do Inicio ao fim\n");
        printf("9 - Eliminar\n");
        printf("10 - Buscar nome retorna endereco\n");
        printf("11 - Buscar nome retorna posicao\n");
        printf("12 - Tamanho da lista\n");
        printf("13 - Destruir\n");
        printf("14 - Sair\n");
printf("=========================================================\n");
        printf("\nopcao: ");
        scanf("%d", &escolha);

return escolha;
}

int main()
{
    //int opcao = 0;
    int posicao;
    char nome[30];
    int r;
    LISTA L;
    CLIENTE c1;
    CLIENTE *cliente_ponteiro;
    criar_Lista(&L);

    r = menu_da_Lista();

    do {


        switch(r){
            case 1:
                criar_Lista(&L); break;

            case 2:
                printf("Nome: ");
                scanf("%s", c1.nome);
                printf("Idade: ");
                scanf("%d", &c1.idade);
                inserir_Inicio(&L, c1); break;
            case 3:
                printf("Nome: ");
                scanf("%s", c1.nome);
                printf("Idade: ");
                scanf("%d", &c1.idade);
                inserir_Final(&L, c1); break;
            case 4:
                printf("Nome: ");
                scanf("%s", c1.nome);
                printf("Idade: ");
                scanf("%d", &c1.idade);
                printf("Posicao: " );
                scanf("%d", &posicao);
                Inserir_Posicao(&L, posicao, c1);
                break;
            case 5:
                printf("Posicao: ");
                scanf("%d", &posicao);
                cliente_ponteiro = Acessar_A_Partir_do_Inicio(&L, posicao);
                if (cliente_ponteiro != NULL){
                printf("nome: %s\n", cliente_ponteiro->nome);
                printf("Idade: %d\n", cliente_ponteiro->idade);
                }
                else
                    printf("Posicao nao existe!!\n\n");
                break;
            case 6:
                printf("Posicao: ");
                scanf("%d", &posicao);
                cliente_ponteiro = Acessar_A_Partir_do_Fim(&L, posicao);
                if (cliente_ponteiro != NULL){
                printf("nome: %s\n", cliente_ponteiro->nome);
                printf("Idade: %d\n", cliente_ponteiro->idade);
                }
                else
                    printf("Posicao nao existe!!\n\n");
                break;
            case 7:
                listar_Inicio_ao_Fim(&L);
                break;
            case 8:
                listar_Fim_ao_Inicio(&L);
                break;
            case 9:
                printf("Posicao: ");
                scanf("%d", &posicao);
                Eliminar_Posicao(&L, posicao);
                break;
            case 10:
                printf("Nome: ");
                scanf("%s", nome);
                cliente_ponteiro = Buscar_Endereco_por_Nome(nome, &L);
                if (cliente_ponteiro != NULL){
                    printf("nome: %s\n", cliente_ponteiro->nome);
                    printf("Idade: %d\n", cliente_ponteiro->idade);
                }
                else
                    printf("Não existe o nome!!\n\n");
                break;
            case 11:
                printf("Nome: ");
                scanf("%s", nome);
                posicao = Buscar_posicao_por_Nome(nome, &L);
                if (posicao >= 0){
                    printf("posicao %d\n", posicao);
                    cliente_ponteiro = Acessar_A_Partir_do_Fim(&L, posicao);
                    //printf("nome: %s\n", cliente_ponteiro->nome);
                    //printf("Idade: %d\n", cliente_ponteiro->idade);
                }
                else
                    printf("Não existe o nome!!\n\n");
                break;
            case 12:
                printf("Tamanho da Lista: %d\n", Tamanho_da_Lista(L));
                break;
            case 13:
                destruir_Lista(&L);
                break;
        }
        system("pause");
        system("cls");
        r = menu_da_Lista();

    }while (r!=14);
return 0;
}
