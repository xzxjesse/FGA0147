#include <stdio.h>

#define exch(A, B) { int t = A; A = B; B = t; }
#define less(A, B) (A < B)

void selection_sort(int *v, int L, int R) {
    for (int i = L; i < R - 1; i++) {
        int min = i;
        for (int j = i + 1; j < R; j++) {
            if (less(v[j], v[min])) {
                min = j;
            }
        }
        exch(v[min], v[i]);
    }
}

int main() {
    int numeros[1001];
    int tamanho = 0;

    while (scanf("%d", &numeros[tamanho]) != EOF) {
        tamanho++;
    }

    selection_sort(numeros, 0, tamanho);

    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d ", numeros[i]);
    }

    if (tamanho > 0) {
        printf("%d\n", numeros[tamanho - 1]);
    }

    return 0;
}
