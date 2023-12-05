#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sequencia {
    int tamanho;
    char caractere;
    int posicao;
   int ordemOriginal;
};

int compararSequencias(const void *a, const void *b) {
    struct Sequencia *seqA = (struct Sequencia *)a;
    struct Sequencia *seqB = (struct Sequencia *)b;

    if (seqA->tamanho != seqB->tamanho) {
        return seqB->tamanho - seqA->tamanho;
    } else {
        return seqA->ordemOriginal - seqB->ordemOriginal;
    }
}

void analisarSequencias(char *string) {
    int len = strlen(string);
    struct Sequencia sequencias[len];
    int count = 0;

    for (int i = 0; i < len; i++) {
        sequencias[count].tamanho = 1;
        sequencias[count].caractere = string[i];
        sequencias[count].posicao = i;
        sequencias[count].ordemOriginal = count;

        while (i + 1 < len && string[i] == string[i + 1]) {
            sequencias[count].tamanho++;
            i++;
        }

        count++;
    }

    qsort(sequencias, count, sizeof(struct Sequencia), compararSequencias);

    for (int i = 0; i < count; i++) {
        printf("%d %c %d\n", sequencias[i].tamanho, sequencias[i].caractere, sequencias[i].posicao);
    }
}

int main() {
    char string[100001];
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    analisarSequencias(string);

    return 0;
}
