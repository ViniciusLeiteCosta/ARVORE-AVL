#include <stdio.h>
#include "avl.h"

int main() {

    No* raiz = NULL;
    int chave,opcao;

    //TESTE COM 10 CHAVES PREDEFINIDAS.
    raiz = inserir_avl(raiz, 10);
    raiz = inserir_avl(raiz, 3);
    raiz = inserir_avl(raiz, 5);
    raiz = inserir_avl(raiz, 9);
    raiz = inserir_avl(raiz, 45);
    raiz = inserir_avl(raiz, 70);
    raiz = inserir_avl(raiz, 50);
    raiz = inserir_avl(raiz, 20);
    raiz = inserir_avl(raiz, 15);
    raiz = inserir_avl(raiz, 8);

    printf("DADOS: [ ");
    preorder_avl(raiz);
    printf("]");

    while(1){

        printf("\nINSERIR (1) | REMOVER (2) | SAIR (-1): ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nDIGITE O NUMERO A SER INSERIDO: ");
                scanf("%d", &chave);
                raiz = inserir_avl(raiz, chave);

                printf("\nARVORE: [ ");
                preorder_avl(raiz);
                printf("]");
                break;
                break;
            case 2:
                printf("\nDIGITE O NUMERO A SER REMOVIDO: ");
                scanf("%d", &chave);
                raiz = remover_avl(raiz, chave);

                printf("\nARVORE: [ ");
                preorder_avl(raiz);
                printf("]");
                break;
            case -1:
                exit(1);
                break;
            default:
                printf("ERRO!");
        }

    }
    return 0;
}
