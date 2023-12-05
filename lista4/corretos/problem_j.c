#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int baixo = 0, alto = tamanho - 1;
    while (baixo <= alto) {
        int meio = baixo + (alto - baixo) / 2;
        if (arr[meio] == alvo)
            return 1;
        else if (arr[meio] < alvo)
            baixo = meio + 1;
        else
            alto = meio - 1;
    }
    return 0;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int proibidos[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &proibidos[i]);
        }

        qsort(proibidos, N, sizeof(int), comparar);

        int consulta;
        while (scanf("%d", &consulta) != EOF) {
            if (buscaBinaria(proibidos, N, consulta)) {
                printf("sim\n");
            } else {
                printf("nao\n");
            }
        }
    }

    return 0;
}