#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

void empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        int novaCapacidade = 2 * p->N;  // Aumenta a capacidade, por exemplo, dobrando-a
        p->dados = (int *)realloc(p->dados, novaCapacidade * sizeof(int));

        if (p->dados == NULL) {
            return 0;
        }

        p->N = novaCapacidade;
    }

    p->dados[p->topo] = x;
    p->topo++;

    return 1;
}

int desempilha(pilha *p, int *y) {
    if (p->topo > 0) {
        p->topo--;
        *y = p->dados[p->topo];
        return 1;
    } else {
        return 0;
    }
}