#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// INICIALIZANDO O NO
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->altura = 1;
    return novoNo;
}

// ALTURA
int altura(No* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

// FB
int calcularFatorBalanceamento(No* no) {
    if (no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

// MAIOR
int calcularMaior(int a, int b) {
    return (a > b) ? a : b;
}

// MINIMO
No* encontrarMinimo(No* no) {
    if (no == NULL || no->esq == NULL)
        return no;
    return encontrarMinimo(no->esq);
}

// ROTACAO A DIREITA
No* rotacaoDireita(No* no) {
    No* filhoEsquerda = no->esq;
    No* filhoDireita = filhoEsquerda->dir;

    filhoEsquerda->dir = no;
    no->esq = filhoDireita;

    no->altura = calcularMaior(altura(no->esq), altura(no->dir)) + 1;
    filhoEsquerda->altura = calcularMaior(altura(filhoEsquerda->esq), altura(filhoEsquerda->dir)) + 1;

    return filhoEsquerda;
}

// ROTACAO A ESQUERDA
No* rotacaoEsquerda(No* no) {
    No* filhoDireita = no->dir;
    No* filhoEsquerda = filhoDireita->esq;

    filhoDireita->esq = no;
    no->dir = filhoEsquerda;

    no->altura = calcularMaior(altura(no->esq), altura(no->dir)) + 1;
    filhoDireita->altura = calcularMaior(altura(filhoDireita->esq), altura(filhoDireita->dir)) + 1;

    return filhoDireita;
}

// INSERIR
No* inserir_avl(No* raiz, int chave) {
    if (raiz == NULL)
        return criarNo(chave);

    if (chave < raiz->chave)
        raiz->esq = inserir_avl(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = inserir_avl(raiz->dir, chave);
    else
        return raiz;

    raiz->altura = calcularMaior(altura(raiz->esq), altura(raiz->dir)) + 1;

    int fatorBalanceamento = calcularFatorBalanceamento(raiz);

    if (fatorBalanceamento > 1 && chave < raiz->esq->chave)
        return rotacaoDireita(raiz);

    if (fatorBalanceamento < -1 && chave > raiz->dir->chave)
        return rotacaoEsquerda(raiz);

    if (fatorBalanceamento > 1 && chave > raiz->esq->chave) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (fatorBalanceamento < -1 && chave < raiz->dir->chave) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// REMOVER
No* remover_avl(No* raiz, int chave) {
    if (raiz == NULL)
        return raiz;

    if (chave < raiz->chave)
        raiz->esq = remover_avl(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = remover_avl(raiz->dir, chave);
    else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            No* temp = raiz->esq ? raiz->esq : raiz->dir;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;

            free(temp);
        } else {
            No* temp = encontrarMinimo(raiz->dir);
            raiz->chave = temp->chave;
            raiz->dir = remover_avl(raiz->dir, temp->chave);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = calcularMaior(altura(raiz->esq), altura(raiz->dir)) + 1;

    int fatorBalanceamento = calcularFatorBalanceamento(raiz);

    if (fatorBalanceamento > 1 && calcularFatorBalanceamento(raiz->esq) >= 0)
        return rotacaoDireita(raiz);

    if (fatorBalanceamento > 1 && calcularFatorBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (fatorBalanceamento < -1 && calcularFatorBalanceamento(raiz->dir) <= 0)
        return rotacaoEsquerda(raiz);

    if (fatorBalanceamento < -1 && calcularFatorBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// PREORDER
void preorder_avl(No* no) {
    if (no != NULL) {
        printf("[%d]", no->chave);
        preorder_avl(no->esq);
        preorder_avl(no->dir);
    }
}

// PREORDER DO ARQUIVO
void preorder_avl_arquivo(No* no, FILE* arquivo) {
    if (no != NULL) {
        fprintf(arquivo, "[%d]", no->chave);
        preorder_avl_arquivo(no->esq, arquivo);
        preorder_avl_arquivo(no->dir, arquivo);
    }
}
