#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
    int altura;
} No;

No* inserir_avl(No* no, int chave);
No* remover_avl(No* no, int chave);
void imprimirPreOrder(No* no);

#endif // AVL_H_INCLUDED
