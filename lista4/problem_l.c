#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PALAVRA_CHAVE 16

typedef struct {
    int codigo;
    char palavraChave[MAX_PALAVRA_CHAVE];
} Instrucao;

int compararInstrucoes(const void *a, const void *b) {
    return ((Instrucao*)a)->codigo - ((Instrucao*)b)->codigo;
}

int buscaBinaria(Instrucao arr[], int tamanho, int alvo) {
    int baixo = 0, alto = tamanho - 1;
    while (baixo <= alto) {
        int meio = baixo + (alto - baixo) / 2;
        if (arr[meio].codigo == alvo)
            return meio;
        else if (arr[meio].codigo < alvo)
            baixo = meio + 1;
        else
            alto = meio - 1;
    }
    return -1;
}

int main() {
    int numInstrucoes;
    scanf("%d", &numInstrucoes);

    Instrucao instrucoes[numInstrucoes];

    for (int i = 0; i < numInstrucoes; i++) {
        scanf("%d %s", &instrucoes[i].codigo, instrucoes[i].palavraChave);
    }

    qsort(instrucoes, numInstrucoes, sizeof(Instrucao), compararInstrucoes);

    int consulta;
    while (scanf("%d", &consulta) != EOF) {
        int posicao = buscaBinaria(instrucoes, numInstrucoes, consulta);

        if (posicao != -1) {
            printf("%s\n", instrucoes[posicao].palavraChave);
        } else {
            printf("undefined\n");
        }
    }

    return 0;
}
