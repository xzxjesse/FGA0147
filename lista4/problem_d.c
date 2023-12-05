#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *v, int L, int R) {
    if (L >= R) {
        return;
    }

    int m = (R + L) / 2;

    merge_sort(v, L, m);
    merge_sort(v, m + 1, R);

    merge(v, L, m, R);
}

void merge(int *v, int L, int m, int R) {
    int tam = R + 1 - L;
    int *aux = malloc(sizeof(int) * tam);

    int i = L;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= R) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i <= m)
        aux[k++] = v[i++];

    while (j <= R)
        aux[k++] = v[j++];

    k = 0;

    for (i = L; i <= R; i++)
        v[i] = aux[k++];

    free(aux);
}

int main (){
    int tamanho;

    scanf("%d", &tamanho);

    int *numeros = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }

    merge_sort(numeros, 0, tamanho - 1);

    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d ", numeros[i]);
    }

    if (tamanho > 0) {
        printf("%d\n", numeros[tamanho - 1]);
    }

    free(numeros);

    return 0;
}