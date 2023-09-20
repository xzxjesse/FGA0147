#include <stdio.h>

char* determinar_vencedor(int R) {
    int aldo = 0;
    int beto = 0;

    for (int i = 0; i < R; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        aldo += A;
        beto += B;
    }

    if (aldo > beto) {
        return "Aldo";
    } else {
        return "Beto";
    }
}

int main() {
    int teste_numero = 1;

    while (1) {
        int R;
        scanf("%d", &R);
        if (R == 0) {
            break;
        }

        char* vencedor = determinar_vencedor(R);

        printf("Teste %d\n", teste_numero);
        printf("%s\n\n", vencedor);
        teste_numero++;
    }

    return 0;
}
