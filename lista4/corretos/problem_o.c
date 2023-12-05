#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int L, int meio, int R) {
    int *aux = malloc(sizeof(int) * (R - L));

    int i = L, j = meio, k = 0;

    while (i < meio && j < R) {
        aux[k++] = (vetor[i] <= vetor[j]) ? vetor[i++] : vetor[j++];
    }

    while (i < meio) {
        aux[k++] = vetor[i++];
    }

    while (j < R) {
        aux[k++] = vetor[j++];
    }

    for (i = L; i < R; i++) {
        vetor[i] = aux[i - L];
    }

    free(aux);
}

void merge_sort(int *vetor, int L, int R) {
    if (R - 1 <= L) {
        return;
    }

    int meio = L + (R - L) / 2;

    merge_sort(vetor, L, meio);
    merge_sort(vetor, meio, R);
    merge(vetor, L, meio, R);
}

int busca_binaria(int *vetor, int size, int target) {
    int min = 0, max = size;

    while (min < max) {
        int meio = min + (max - min) / 2;

        if (vetor[meio] == target) {
            return meio;
        }

        if (vetor[meio] > target) {
            max = meio;
        } else {
            min = meio + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int vetor[200000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    merge_sort(vetor, 0, n);

    int novo_index = 0;
    for (int i = 1; i < n; i++) {
        if (vetor[novo_index] != vetor[i]) {
            vetor[++novo_index] = vetor[i];
        }
    }

    novo_index++;

    if (novo_index % 2 != 0) {
        vetor[novo_index++] = 1000000000;
    }

    int numero_index = novo_index;
    for (int i = 1; i < novo_index; i += 2) {
        vetor[numero_index] = vetor[i] + vetor[i - 1];

        if (busca_binaria(vetor, novo_index, vetor[numero_index]) == -1) {
            numero_index++;
        }
    }

    merge_sort(vetor, 0, numero_index);

    for (int i = 0; i < numero_index; i += 4) {
        printf("%d\n", vetor[i]);
    }

    printf("Elementos: %d\n", numero_index);

    return 0;
}