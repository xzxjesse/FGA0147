#include <stdio.h>

void moverXParaOFinal(char *principal) {
    if (*principal == '\0') {
        return;
    }

    if (*principal == 'x') {
        moverXParaOFinal(principal + 1);
        *principal = '\0';
        printf("x");
    } else {
        printf("%c", *principal);
        moverXParaOFinal(principal + 1);
    }
}

int main() {
    char principal[10001];

    scanf("%s", principal);

    moverXParaOFinal(principal);

    printf("\n");

    return 0;
}