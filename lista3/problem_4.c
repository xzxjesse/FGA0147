#include <stdio.h>

typedef struct fila {
int *dados;
int N, p, u;
} fila;

int enfileira (fila *f, int *x){
    if (f == NULL || f->dados == NULL || f->p == f->u) {
        return 0;
    }

    if ((f->p + 1) % f->N == f->u) {
        int novoTamanho = f->N * 2;
        int *novoDados = (int *)malloc(sizeof(int) * novoTamanho);

        if (novoDados == NULL) {
            return 0;
        }

        int j = 0;
        for (int i = f->u; i != f->p; i = (i + 1) % f->N) {
            novoDados[j] = f->dados[i];
            j++;
        }

        novoDados[j] = x;

        free(f->dados);
        f->dados = novoDados;
        f->N = novoTamanho;
        f->p = j;
        f->u = 0;
    } else {
        f->dados[f->p] = x;
        f->p = (f->p + 1) % f->N;
    }

    return 1;
}