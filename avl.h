#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
    int altura;
} No;

No* criarNo(int chave);
int altura(No* no);
int calcularFatorBalanceamento(No* no);
int calcularMaior(int a, int b);
No* encontrarMinimo(No* no);
No* rotacaoDireita(No* no);
No* rotacaoEsquerda(No* no);
No* inserir_avl(No* raiz, int chave);
No* remover_avl(No* raiz, int chave);
void preorder_avl_arquivo(No* no, FILE* arquivo);

#endif 

