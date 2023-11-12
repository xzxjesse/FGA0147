#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    if (f == NULL) {
        return 0;
    }

    if (((f->u + 1) % f->N) == f->p) {
        int novoN = f->N * 2;
        int *novo_dados = (int *)malloc(novoN * sizeof(int));

        if (novo_dados == NULL) {
            return 0;
        }

        int j = 0;
        for (int i = f->p; i != f->u; i = (i + 1) % f->N) {
            novo_dados[j] = f->dados[i];
            j++;
        }

        free(f->dados);
        f->dados = novo_dados;
        f->p = 0;
        f->u = j;
        f->N = novoN;
    }

    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}

//Wrong Answer,0p