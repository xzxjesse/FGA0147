#include <stdio.h>
#include <string.h>

#define MAX 10000
#define R 5
#define maxstring 101

int aux[MAX];

int digit(int num, int pos) {
    int divisor = 1;
    for (int i = 0; i < pos; i++)
        divisor *= 10;
    return (num / divisor) % 10;
}

void countingsort(int *v, int l, int r) {
    int i, count[R + 1];

    // Inicialização: Zerando o array de contagem
    for (i = 0; i <= R; i++){
        count[i] = 0;
    }

    // Contagem de frequências
    for (i = l; i <= r; i++){
        count[v[i] + 1]++;
    }

    // Cálculo das posições
    for (i = 1; i <= R; i++){
        count[i] += count[i - 1];
    }

    // Distribuição
    for (i = l; i <= r; i++) {
        aux[count[v[i]]] = v[i];
        count[v[i]]++;
    }

    // Cópia de volta: a partir de aux[0]
    for (i = l; i <= r; i++){
        v[i] = aux[i - l];
    }
}

// Função de ordenação Radix Sort LSD
void radix_sortLSD(int *v, int l, int r, int bytesword) {
    int i, w;
    int aux[r - l + 1], count[R + 1];

    for (w = 0; w < bytesword; w++) {
        // Inicialização do array de contagem
        memset(count, 0, sizeof(int) * (R + 1));

        // Contagem de frequências
        for (i = l; i <= r; i++)
            count[digit(v[i], w) + 1]++;

        // Cálculo das posições
        for (i = 1; i <= R; i++)
            count[i] += count[i - 1];

        // Distribuição
        for (i = l; i <= r; i++) {
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }

        // Copiando de volta: a partir de aux[0]
        for (i = l; i <= r; i++)
            v[i] = aux[i - l];
    }
}


// Strings: ordena para o d-ésimo caractere
void radixMSD(char a[][maxstring], int l, int r, int d) {
    if (r <= l)
        return;

    char aux[r - l + 1][maxstring];

    int count[R + 1];
    memset(count, 0, sizeof(int) * (R + 1));

    // frequencia dos d-ésimos caracteres
    for (int i = l; i <= r; i++)
        count[charAt(a[i], d) + 1]++;

    // tabela de índices: calculando as posições
    for (int i = 1; i <= R; i++)
        count[i] += count[i - 1];

    // redistribui as chaves: ordena em aux
    for (int i = l; i <= r; i++)
        strcpy(aux[count[charAt(a[i], d)]++], a[i]);

    // copia para o original
    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]);

    // ordenar por subconjunto: count[0] = já ordenadas
    for (int i = 1; i <= R; i++) {
        // count[i-1] posição da primeira chave com o caractere i
        // count[i]-1 posição da última chave com o caractere i
        radixMSD(a, l + count[i - 1], l + count[i] - 1, d + 1);
    }
}

// Inteiros: ordena o w-ésimo byte
void radix_sortMSD(int *v, int l, int r, int w) {
    if (r <= l || w < 0)
        return;

    int i, aux[r - l + 1], count[R + 1];
    memset(count, 0, sizeof(int) * (R + 1));

    for (i = l; i <= r; i++)
        count[digit(v[i], w) + 1]++;

    for (i = 1; i <= R; i++)
        count[i] += count[i - 1];

    for (i = l; i <= r; i++)
        aux[count[digit(v[i], w)]++] = v[i];

    for (i = l; i <= r; i++)
        v[i] = aux[i - l];

    // ordenando os que começam por zero
    radix_sortMSD(v, l, l + count[0] - 1, w - 1);
    for (i = 1; i <= R; i++)
        radix_sortMSD(v, l + count[i - 1], l + count[i] - 1, w - 1);
}