#include <stdio.h>

int encontrarIndice(int x, int conjunto[], int tamanho) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (conjunto[meio] < x) {
            inicio = meio + 1;
        } else if (conjunto[meio] > x) {
            fim = meio - 1;
        } else {
            return meio;  
        }
    }

    return inicio;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    int conjunto[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &conjunto[i]);
    }

    for (int i = 0; i < M; i++) {
        int numeroBusca;
        scanf("%d", &numeroBusca);

        int indice = encontrarIndice(numeroBusca, conjunto, N);

        printf("%d\n", indice);
    }

    return 0;
}
