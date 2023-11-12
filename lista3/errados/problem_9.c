#include <stdio.h>

int main() {
    int n;
    
    // Leitura do valor de n
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Verificação se n é maior ou igual a 2
    if (n < 2) {
        printf("O valor de n deve ser maior ou igual a 2.\n");
        return 1;
    }

    int cartas[n];
    int topo = 0; // Índice do topo da pilha
    int base = n - 1; // Índice da base da pilha

    // Inicialização das cartas
    for (int i = 0; i < n; i++) {
        cartas[i] = i + 1;
    }

    // Processamento do jogo
    printf("Cartas descartadas:");
    while (topo < base) {
        printf(" %d", cartas[topo]);  // Removi a vírgula desta linha
        topo += 1;  // Incrementa o topo
        cartas[base + 1] = cartas[topo];  // Move a carta para a base
        topo += 1;  // Incrementa o topo para a próxima carta
        base++;     // Incrementa a base

        // Adiciona uma vírgula se ainda houver mais cartas a serem descartadas
        if (topo < base) {
            printf(",");
        }
    }
    printf("\nCarta restante: %d\n", cartas[topo]);

    return 0;
}


/*
Digite o valor de n: 12
Cartas descartadas: 1, 3, 5, 7, 9, 11, 2, 6, 10, 4,
*/