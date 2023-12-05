#include <stdio.h>

int encontrarIndice(int x, int conjunto[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (conjunto[i] == x) {
            return i;
        }
    }
    return -1;
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

//Time Limit Exceeded,50p