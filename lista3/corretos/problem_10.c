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

/*
Chamada Inicial: inverter("Hello")

Verifica se o primeiro caractere é '\0' (não é).
Chama inverter("ello").
Chamada Recursiva 1: inverter("ello")

Verifica se o primeiro caractere é '\0' (não é).
Chama inverter("llo").
Chamada Recursiva 2: inverter("llo")

Verifica se o primeiro caractere é '\0' (não é).
Chama inverter("lo").
Chamada Recursiva 3: inverter("lo")

Verifica se o primeiro caractere é '\0' (não é).
Chama inverter("o").
Chamada Recursiva 4: inverter("o")

Verifica se o primeiro caractere é '\0' (não é).
Chama inverter("").
Chamada Recursiva 5: inverter("")

Agora, o primeiro caractere é '\0', então a recursão para.
A função retorna para a chamada anterior (inverter("o")) e imprime 'o'.
Retorno Recursivo 4: A função agora retorna para a chamada inverter("lo") e imprime 'l'.

Retorno Recursivo 3: A função retorna para a chamada inverter("llo") e imprime 'l'.

Retorno Recursivo 2: A função retorna para a chamada inverter("ello") e imprime 'e'.

Retorno Recursivo 1: A função retorna para a chamada inicial inverter("Hello") e imprime 'H'.

EMPILHAMENTO
*/