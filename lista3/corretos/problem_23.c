#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    no *pilha[100];
    int topo = -1;

    no *atual = raiz;

    while (atual != NULL || topo != -1) {
        while (atual != NULL) {
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        atual = pilha[topo--];
        printf("%d ", atual->dado);

        atual = atual->dir;
    }
}

no *cria_no(int dado) {
    no *novo_no = (no *)malloc(sizeof(no));
    if (novo_no == NULL) {
        exit(EXIT_FAILURE);
    }

    novo_no->dado = dado;
    novo_no->esq = novo_no->dir = NULL;

    return novo_no;
}

void libera_arvore(no *raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}