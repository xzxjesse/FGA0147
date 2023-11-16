#include <stdio.h>

int main() {
    int m;
    int teste = 1;

    while (1) {
        scanf("%d", &m);

        if (m == 0) {
            break;
        }

        char operador;
        int operando;
        int resultado;

        scanf("%d", &resultado);

        for (int i = 1; i < m; i++) {
            scanf(" %c %d", &operador, &operando);

            if (operador == '+') {
                resultado += operando;
            } else if (operador == '-') {
                resultado -= operando;
            }
        }

        printf("Teste %d\n", teste);
        printf("%d\n\n", resultado);

        teste++;
    }

    return 0;
}
