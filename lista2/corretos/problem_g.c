 #include <stdio.h>

int contadorPares(char *entrada, int indice) {
    if (entrada[indice] == '\0' || entrada[indice + 1] == '\0') {
        return 0;
    }

    if (entrada[indice] == entrada[indice + 2]) {
        return 1 + contadorPares(entrada + 1, indice);
    }

    return contadorPares(entrada + 1, indice);
}

int main() {
    char entrada[201];
    scanf("%s", entrada);

    int pares = contadorPares(entrada, 0);

    printf("%d\n", pares);

    return 0;
}