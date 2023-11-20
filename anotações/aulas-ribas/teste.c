#include <stdio.h>
#include <stdlib.h>

typedef int item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) { item t = A; A = B; B = t; }
#define cmpexch(A, B) if (less(B, A)) exch(A, B)

void insertion_sort_h(item *v, int L, int R, int h) {
    for (int i = L + h; i <= R; i++) {
        int j = i;
        item tmp = v[i];
        while (j >= L + h && less(tmp, v[j - h])) {
            v[j] = v[j - h];
            j -= h;
        }
        v[j] = tmp;
    }
}

void shell_sort(item *v, int L, int R) {
    int h;
    for (h = 1; h <= (R - L) / 9; h = 3 * h + 1) {
    }

    for (; h > 0; h = h / 3) {
        insertion_sort_h(v, L, R, h);
        printf("Shell Sort: ");
        for (int k = 0; k <= R; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}


void selection_sort(item *v, int L, int R) {
    for (int i = L; i < R; i++) {
        int min = i;
        for (int j = i + 1; j <= R; j++) {
            if (less(v[j], v[min])) {
                min = j;
            }
        }
        exch(v[i], v[min]);
        printf("Selection Sort: ");
        for (int k = 0; k <= R; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

void bubble_sort(item *v, int L, int R) {
    for (int i = L; i < R; i++) {
        for (int j = L; j < R; j++) {
            if (less(v[j + 1], v[j])) {
                exch(v[j + 1], v[j]);
                printf("Bubble Sort: ");
                for (int k = 0; k <= R; k++) {
                    printf("%d ", v[k]);
                }
                printf("\n");
            }
        }
    }
}

void bubble_sort_direto(item *v, int L, int R) {
    for (int i = L; i < R; i++) {
        for (int j = L; j < R; j++) {
            cmpexch(v[j], v[j + 1]);
            printf("Bubble Sort Direto: ");
            for (int k = 0; k <= R; k++) {
                printf("%d ", v[k]);
            }
            printf("\n");
        }
    }
}

void bubble_sort_melhorado(item *v, int L, int R) {
    int troca;
    for (int i = L; i < R; i++) {
        troca = 0;
        for (int j = L; j < R - i - 1; j++) {
            cmpexch(v[j], v[j + 1]);
            troca = 1;
            printf("Bubble Sort Melhorado: ");
            for (int k = 0; k <= R; k++) {
                printf("%d ", v[k]);
            }
            printf("\n");
        }
        if (!troca) {
            break;
        }
    }
}

void insertion_sort(item *v, int L, int R) {
    for (int i = L + 1; i <= R; i++) {
        for (int j = i; j > L; j--) {
            cmpexch(v[j], v[j - 1]);
            printf("Insertion Sort: ");
            for (int k = 0; k <= R; k++) {
                printf("%d ", v[k]);
            }
            printf("\n");
        }
    }
}

void insertion_sort_otimizado(item *v, int L, int R) {
    for (int i = R; i > L; i--) {
        cmpexch(v[i], v[i - 1]);
        printf("Insertion Sort Otimizado: ");
        for (int k = 0; k <= R; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }

    for (int i = L + 2; i <= R; i++) {
        int j = i;
        item tmp = v[j];
        while (less(tmp, v[j - 1])) {
            v[j] = v[j - 1];
            j--;
            printf("Insertion Sort Otimizado: ");
            for (int k = 0; k <= R; k++) {
                printf("%d ", v[k]);
            }
            printf("\n");
        }
        v[j] = tmp;
        printf("Insertion Sort Otimizado: ");
        for (int k = 0; k <= R; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

int main(void) {
    item vetor[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    printf("Vetor Original: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    selection_sort(vetor, 0, 9);

    int vetor_bubble[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    bubble_sort(vetor_bubble, 0, 9);

    int vetor_direto[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    bubble_sort_direto(vetor_direto, 0, 9);

    int vetor_melhorado[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    bubble_sort_melhorado(vetor_melhorado, 0, 9);

    int vetor_insertion[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    insertion_sort(vetor_insertion, 0, 9);

    int vetor_insertion_otimizado[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    insertion_sort_otimizado(vetor_insertion_otimizado, 0, 9);

    int vetor_shell[10] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    shell_sort(vetor_shell, 0, 9);

    return 0;
}