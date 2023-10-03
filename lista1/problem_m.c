#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n < 1 || n > 10000) {
        return 0;
    }

    int numeros[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);

        if (numeros[i] < -1000000 || numeros[i] > 1000000) {
            return 0;
        }
    }

    int menor = numeros[0];
    int indice = 0;

    for (int i = 1; i < n; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
            indice = i;
        }
    }

    printf("%d\n", indice);

    return 0;
}