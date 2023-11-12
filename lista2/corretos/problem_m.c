#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    if (le == NULL) {
        return NULL;
    }

    celula *atual = le->prox;
    while (atual != NULL) {
        if (atual->dado == x) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; // Retorna NULL se o elemento não for encontrado.
}

celula *busca_rec(celula *le, int x) {
    if (le == NULL) {
        return NULL;
    }
    if (le->dado == x) {
        return le;
    }
    return busca_rec(le->prox, x);
}