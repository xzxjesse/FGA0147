#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));

    if (nova_celula == NULL) {
        return NULL;
    }

    nova_celula->dado = x;
    nova_celula->prox = f;

    return nova_celula;
}


//Time Limit Exceeded,0p	