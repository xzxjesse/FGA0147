#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

void bubble_sort_direto(int *v, int L, int R) {
    for (int i = L; i < R; i++) {
        for (int j = L; j < R - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[MAX_SIZE];
    int tamanho = 0;

    while (scanf("%d", &numeros[tamanho]) != EOF) {
        tamanho++;
    }

    bubble_sort_direto(numeros, 0, tamanho);

    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d ", numeros[i]);
    }

    if (tamanho > 0) {
        printf("%d\n", numeros[tamanho - 1]);
    }

    return 0;
}
