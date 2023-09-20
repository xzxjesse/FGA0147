#include <stdio.h>

int main() {
    int N, C, S, E, i;
    int ocupacao = 0;
    int excedeu = 0;

    scanf("%d %d", &N, &C);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &S, &E);

        ocupacao -= S;
        ocupacao += E;

        if (ocupacao > C) {
            excedeu ++;
        }
    }

    if (excedeu) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
