#include <stdio.h>
#include <string.h>

int somaDosDigitos(char *str) {
    if (*str == '\0') {
        return 0;
    }

    char digito = *str;

    if (digito >= '0' && digito <= '9') {
        int valorDigito = digito - '0';
        return valorDigito + somaDosDigitos(str + 1);
    } else {
        return somaDosDigitos(str + 1);
    }
}

int main() {
    char str[100];
    scanf("%s", str);

    int resultado = somaDosDigitos(str);

    printf("%d\n", resultado);

    return 0;
}