#include <stdio.h>
#include <string.h>

void inverter(char *principal) {
    if (*principal == '\0') {
        return;
    }

    inverter(principal+1);

    if (*principal != '\0') {
        printf("%c", *principal);
    }
}

int main() {
    char principal[501];

    scanf("%s", principal);

    inverter(principal);

    printf("\n");

    return 0;
}