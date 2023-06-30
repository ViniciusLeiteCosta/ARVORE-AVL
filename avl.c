#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//INICIALIZANDO O NO
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->altura = 1;
    return novoNo;
}

//ALTURA
int altura(No* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

//FB
int calcularFatorBalanceamento(No* no) {
    if (no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

//MAIOR
int calcularMaior(int a, int b) {
    return (a > b) ? a : b;
}

//MINIMO
No* encontrarMinimo(No* no) {
    if (no == NULL || no->esq == NULL)
        return no;
    return encontrarMinimo(no->esq);
}

//ROTACAO A DIREITA
No* rotacaoDireita(No* no) {
    No* filhoEsquerda = no->esq;
    No* filhoDireita = filhoEsquerda->dir;

    filhoEsquerda->dir = no;
    no->esq = filhoDireita;

    no->altura = calcularMaior(altura(no->esq), altura(no->dir)) + 1;
    filhoEsquerda->altura = calcularMaior(altura(filhoEsquerda->esq), altura(filhoEsquerda->dir)) + 1;

    return filhoEsquerda;
}

//ROTACAO A ESQUERDA
No* rotacaoEsquerda(No* no) {
    No* filhoDireita = no->dir;
    No* filhoEsquerda = filhoDireita->esq;

    filhoDireita->esq = no;
    no->dir = filhoEsquerda;

    no->altura = calcularMaior(altura(no->esq), altura(no->dir)) + 1;
    filhoDireita->altura = calcularMaior(altura(filhoDireita->esq), altura(filhoDireita->dir)) + 1;

    return filhoDireita;
}

//INSERIR (o.O)
No* inserir_avl(No* no, int chave) {
    if (no == NULL)
        return criarNo(chave);

    if (chave < no->chave)
        no->esq = inserir_avl(no->esq, chave);
    else if (chave > no->chave)
        no->dir = inserir_avl(no->dir, chave);
    else
        return no;

    no->altura = calcularMaior(altura(no->esq), altura(no->dir)) + 1;

    int fatorBalanceamento = calcularFatorBalanceamento(no);

    if (fatorBalanceamento > 1 && chave < no->esq->chave)
        return rotacaoDireita(no);

    if (fatorBalanceamento < -1 && chave > no->dir->chave)
        return rotacaoEsquerda(no);

    if (fatorBalanceamento > 1 && chave > no->esq->chave) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (fatorBalanceamento < -1 && chave < no->dir->chave) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

//REMOVER (O.o)
No* remover_avl(No* no, int chave) {
    if (no == NULL)
        return no;

    if (chave < no->chave)
        no->esq = remover_avl(no->esq, chave);
    else if (chave > no->chave)
        no->dir = remover_avl(no->dir, chave);
    else {
        if (no->esq == NULL || no->dir == NULL) {
            No* temp = no->esq ? no->esq : no->dir;

            if (temp == NULL) {
                temp = no;
                no = NULL;
            } else
                *no = *temp;

            free(temp);
        } else {
            No* temp = encontrarMinimo(no->dir);
            no->chave = temp->chave;
            no->dir = remover_avl(no->dir, temp->chave);
        }
    }

    if (no == NULL)
        return no;

    no->altura = calcularMaior(altura(no->esq), altura(no->dir)) + 1;

    int fatorBalanceamento = calcularFatorBalanceamento(no);

    if (fatorBalanceamento > 1 && calcularFatorBalanceamento(no->esq) >= 0)
        return rotacaoDireita(no);

    if (fatorBalanceamento > 1 && calcularFatorBalanceamento(no->esq) < 0) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (fatorBalanceamento < -1 && calcularFatorBalanceamento(no->dir) <= 0)
        return rotacaoEsquerda(no);

    if (fatorBalanceamento < -1 && calcularFatorBalanceamento(no->dir) > 0) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

//PREORDER
void preorder_avl(No* no) {
    if (no != NULL) {
        printf("%d ", no->chave);
        preorder_avl(no->esq);
        preorder_avl(no->dir);
    }
}
