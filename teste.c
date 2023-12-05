#include <stdio.h>

int buscaBinaria(int arr[], int baixo, int alto, int alvo) {
    while (baixo <= alto) {
        int meio = baixo + (alto - baixo) / 2;
        if (arr[meio] == alvo)
            return 1; // Encontrou o número na lista proibida
        else if (arr[meio] < alvo)
            baixo = meio + 1;
        else
            alto = meio - 1;
    }
    return 0; // Não encontrou o número na lista proibida
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int proibidos[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &proibidos[i]);
        }

        int consulta;
        while (scanf("%d", &consulta) != EOF) {
            if (buscaBinaria(proibidos, 0, N - 1, consulta)) {
                printf("sim\n");
            } else {
                printf("nao\n");
            }
        }
    }

    return 0;
}
