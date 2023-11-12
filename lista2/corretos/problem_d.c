#include <stdio.h>
#include <string.h>

int calcularDigitoSoma(char* numero) {
    int comprimento = strlen(numero);
    int soma = 0;

    for (int i = 0; i < comprimento; i++) {
        soma += numero[i] - '0';
    }

    return soma;
}

// Função recursiva para calcular o grau-9 de um número
int calcularGrau9(char* numero, int grau) {
    int soma = calcularDigitoSoma(numero);

    if (soma == 9) {
        return grau;
    }
    else if (soma < 9 && strlen(numero) == 1) {
        return -1; // Não é múltiplo de 9
    }
    else {
        char novoNumero[1002];
        sprintf(novoNumero, "%d", soma);
        return calcularGrau9(novoNumero, grau + 1);
    }
}

int main() {
    char numero[1002];
    int casoNumero = 1;

    while (1) {
        scanf("%s", numero);

        if (numero[0] == '0') {
            break;
        }

        int grau = calcularGrau9(numero, 1);

        if (grau == -1) {
            printf("%s is not a multiple of 9.\n", numero);
        } else {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grau);
        }

        casoNumero++;
    }

    return 0;
}