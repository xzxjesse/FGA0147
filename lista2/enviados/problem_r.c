#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0; // Não é possível remover o próximo elemento
    }

    celula *temp = p->prox;
    p->prox = p->prox->prox;
    free(temp);

    return 1;
}

void remove_elemento(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            anterior->prox = atual->prox;
            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            celula *temp = atual;
            anterior->prox = atual->prox;
            free(temp);
            atual = anterior->prox;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}