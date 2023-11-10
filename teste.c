#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y) {
    if (f == NULL) {
        return 0;
    }

    celula *temp = f;

    printf("Valor de temp: %p\n", (void *)temp); // Imprime o endereço de memória de temp
    *y = temp->dado;
    
    printf("Valor de y: %d\n", *y); // Imprime o valor de y
    f = temp->prox;

    printf("Valor de f: %p\n", (void *)f); // Imprime o endereço de memória de f
    free(temp);

    return 1;
}

int main() {
    celula *fila = (celula *)malloc(sizeof(celula)); // Cria uma célula para a fila
    fila->dado = 42;
    fila->prox = NULL;

    int elemento;
    printf("Fila inicial:\n");
    printf("Valor de fila: %p\n", (void *)fila); // Imprime o endereço de memória da fila
    printf("Valor de fila->dado: %d\n", fila->dado); // Imprime o valor da célula na fila
    printf("Valor de fila->prox: %p\n", (void *)(fila->prox)); // Imprime o endereço de memória do próximo elemento (deve ser NULL)

    if (desenfileira(fila, &elemento)) {
        printf("Elemento desenfileirado: %d\n", elemento);
    } else {
        printf("A fila está vazia. Não é possível desenfileirar.\n");
    }

    printf("Fila após o desenfileiramento:\n");
    printf("Valor de fila: %p\n", (void *)fila); // Imprime o endereço de memória da fila (deve ser o mesmo)
    printf("Valor de fila->dado: %d\n", fila->dado); // Imprime o valor da célula na fila
    printf("Valor de fila->prox: %p\n", (void *)(fila->prox)); // Imprime o endereço de memória do próximo elemento (deve ser NULL)

    free(fila); // Libera a memória da célula da fila

    return 0;
}
