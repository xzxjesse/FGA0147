#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tradutor {
    char japones[100];
    char portugues[100];
} Tradutor;

void merge(Tradutor *vetor, int L, int meio, int R) {
    Tradutor *aux = malloc(sizeof(Tradutor) * (R - L));

    int i = L, j = meio, k = 0;
    while (i < meio && j < R){
        aux[k++] = strcmp(vetor[i].japones, vetor[j].japones) <= 0 ? vetor[i++] : vetor[j++];
    }
    while (i < meio){
        aux[k++] = vetor[i++];
    }
    while (j < R){
        aux[k++] = vetor[j++];
    }
    for (i = L; i < R; i++){
        vetor[i] = aux[i - L];
    }
    free(aux);
}

void merge_sort(Tradutor *vetor, int L, int R) {
    if (R - 1 <= L) {
        return;
    }

    int meio = L + (R - L) / 2;

    merge_sort(vetor, L, meio);
    merge_sort(vetor, meio, R);
    merge(vetor, L, meio, R);
}

int busca_binaria(Tradutor *vetor, int size, char *data) {
    int min = 0, max = size;

    while (max >= min) {
        int meio = min + (max - min) / 2;
        if (!strcmp(vetor[meio].japones, data)) {
            return meio;
        } else if (strcmp(vetor[meio].japones, data) > 0) {
            max = meio - 1;
        } else {
            min = meio + 1;
        }
    }
    return -1;
}

int main() {
    int teste;
    scanf("%d", &teste);

    while (teste--) {
        int m, n;
        scanf("%d %d", &m, &n);

        Tradutor *vetor = malloc(sizeof(Tradutor) * m);
        char frase[100];

        for (int i = 0; i < m; i++) {
            scanf("\n");
            fgets(vetor[i].japones, sizeof(vetor[i].japones), stdin);
            fgets(vetor[i].portugues, sizeof(vetor[i].portugues), stdin);

            vetor[i].japones[strcspn(vetor[i].japones, "\n")] = '\0';
            vetor[i].portugues[strcspn(vetor[i].portugues, "\n")] = '\0';
        }

        merge_sort(vetor, 0, m);

        while (n--) {
            int index = 0;
            int palavra_index = 0;

            scanf("\n");
            fgets(frase, sizeof(frase), stdin);
            frase[strcspn(frase, "\n")] = '\0';

            while (1) {
                char palavra[100];
                while (frase[index] != ' ' && frase[index] != '\0'){
                    palavra[palavra_index++] = frase[index++];
                }
                palavra[palavra_index] = '\0';
                index++;

                int response = busca_binaria(vetor, m, palavra);

                if (response == -1){
                    printf("%s", palavra);
                }else{
                    printf("%s", vetor[response].portugues);
                }

                if (frase[index] == '\0'){
                    break;
                }else{
                    printf(" ");
                }

                palavra_index = 0;
            }
            printf("\n");
        }
    }

    return 0;
}