#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *atual = le->prox;

    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }

    printf(" -> NULL\n");
}

void imprime_rec(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }
    
    printf("%d", le->dado);
    if (le->prox != NULL) {
        printf(" -> ");
    } else {
        printf(" -> NULL\n");
    }
    
    imprime_rec(le->prox);
}