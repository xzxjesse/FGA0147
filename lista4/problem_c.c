#include <stdio.h>
#include <stdlib.h>

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))

void insertion_sort_h(int *v, int L, int R, int h) {
    for (int i = L + h; i <= R; i++) {
        int j = i;
        int tmp = v[i];
        while (j >= L + h && less(tmp, v[j - h])) {
            v[j] = v[j - h];
            j -= h;
        }
        v[j] = tmp;
    }
}

void shell_sort(int *v, int L, int R) {
    int h;
    if ((R - L) / 9 < 1) {
        h = 1;
    } else {
        for (h = 1; h <= (R - L) / 9; h = 3 * h + 1) {
        }
    }

    for (; h > 0; h = h / 3) {
        insertion_sort_h(v, L, R, h);
    }
}

int main() {
    int *vetor = malloc(50001 * sizeof(int));
    int numero;
    int i = 0;

    while (i < 50001 && scanf("%d", &numero) == 1) {
        vetor[i] = numero;
        i++;
    }

    shell_sort(vetor, 0, i - 1);

    printf("%d", vetor[0]);

    for (int j = 1; j < i; j++) {
        printf(" %d", vetor[j]);
    }

    printf("\n");

    free(vetor);

    return 0;
}