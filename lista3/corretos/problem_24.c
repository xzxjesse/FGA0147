#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct {
    no **dados;
    int capacidade, topo;
} Pilha;

Pilha* criaPilha(int capacidade) {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL) {
        exit(EXIT_FAILURE);
    }

    p->dados = (no **)malloc(capacidade * sizeof(no *));
    if (p->dados == NULL) {
        exit(EXIT_FAILURE);
    }

    p->capacidade = capacidade;
    p->topo = -1;

    return p;
}

void empilha(Pilha *p, no *valor) {
    if (p->topo == p->capacidade - 1) {
        exit(EXIT_FAILURE);
    }

    p->dados[++p->topo] = valor;
}

no* desempilha(Pilha *p) {
    if (pilhaVazia(p)) {
        exit(EXIT_FAILURE);
    }

    return p->dados[p->topo--];
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha *pilha = criaPilha(100);
    no *ultimoVisitado = NULL;

    while (raiz != NULL || !pilhaVazia(pilha)) {
        if (raiz != NULL) {
            empilha(pilha, raiz);
            raiz = raiz->esq;
        } else {
            no *topo = pilha->dados[pilha->topo];
            if (topo->dir != NULL && topo->dir != ultimoVisitado) {
                raiz = topo->dir;
            } else {
                printf("%d ", topo->dado);
                ultimoVisitado = desempilha(pilha);
            }
        }
    }

    free(pilha->dados);
    free(pilha);
}

no* criaNo(int dado) {
    no *novoNo = (no *)malloc(sizeof(no));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = dado;
    novoNo->esq = novoNo->dir = NULL;

    return novoNo;
}

void liberaArvore(no *raiz) {
    if (raiz != NULL) {
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz);
    }
}