#include <stdio.h>

void trocar(char *principal) {
    if (*principal == '\0') {
        return;
    }

    if (*principal == 'x') {
        printf("y");
        trocar(principal + 1);
    } else {
        printf("%c", *principal);
        trocar(principal + 1);
    }
}

int main() {
    char principal[81];

    scanf("%s", principal);

    trocar(principal);

    printf("\n");

    return 0;
}