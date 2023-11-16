#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int topo;
    int capacidade;
} Pilha;

Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->arr = (int *)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

void empilhar(Pilha *pilha, int item) {
    pilha->arr[++pilha->topo] = item;
}

int desempilhar(Pilha *pilha) {
    return pilha->arr[pilha->topo--];
}

int ePossivelOrdenarLoveMobiles(int *ordem, int n) {
    Pilha *pilha = criarPilha(n);
    int loveMobileEsperado = 1;

    for (int i = 0; i < n; i++) {
        while (pilha->topo != -1 && pilha->arr[pilha->topo] == loveMobileEsperado) {
            desempilhar(pilha);
            loveMobileEsperado++;
        }

        if (ordem[i] == loveMobileEsperado) {
            loveMobileEsperado++;
        } else {
            empilhar(pilha, ordem[i]);
        }
    }

    while (pilha->topo != -1 && pilha->arr[pilha->topo] == loveMobileEsperado) {
        desempilhar(pilha);
        loveMobileEsperado++;
    }

    int resultado = pilha->topo == -1;

    free(pilha->arr);
    free(pilha);

    return resultado;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        int *ordem = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &ordem[i]);
        }

        if (ePossivelOrdenarLoveMobiles(ordem, n)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        free(ordem);
    }

    return 0;
}