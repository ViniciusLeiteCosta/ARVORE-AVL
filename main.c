#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
    
    No* raiz = NULL;
    int opcao, chave;
    FILE* entrada = fopen("entrada.in", "r");
    FILE* saida = fopen("saida.out", "w");

    if (entrada == NULL) {
        printf("ERRO - ENTRADA.\n");
        return 1;
    }

    if (saida == NULL) {
        printf("ERRO - SAIDA.\n");
        return 1;
    }

    // ler as chaves de entrada.in
    while (fscanf(entrada, "%d", &chave) == 1) {
        raiz = inserir_avl(raiz, chave);
    }

    fclose(entrada);

    do {
        printf("\nEscolha uma opcao: (1) INSERIR | (2) PREORDER | (3) REMOVER | (99) SAIR:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nINSERIR: ");
                scanf("%d", &chave);
                raiz = inserir_avl(raiz, chave);
                break;
            case 2:
                printf("\nPREORDER: ");
                preorder_avl(raiz);
                printf("\n");
                break;
            case 3:
                printf("\nREMOVER: ");
                scanf("%d", &chave);
                raiz = remover_avl(raiz, chave);
                break;
            case 99:
            	 printf("\nPREORDER: ");
            	 preorder_avl(raiz);
                printf("\nFIM.\n");
                break;
            default:
                printf("\nERRO!\n");
                break;
        }
    } while (opcao != 99);

    // printar a saida no arquivo
    fprintf(saida, "PREORDER: ");
    preorder_avl_arquivo(raiz, saida);

    fclose(saida);

    return 0;
}

