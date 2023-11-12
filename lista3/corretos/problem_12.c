#include <stdio.h>

#define MAX_PARTICIPANTES 101

int jogo_vivo_morto(int P, int R, int fila[], int rodadas[][MAX_PARTICIPANTES]) {
    int i, j;

    for (i = 0; i < R; i++) {
        int N = rodadas[i][0];
        int J = rodadas[i][1];
        int acoes[MAX_PARTICIPANTES];

        for (j = 0; j < N; j++) {
            acoes[j] = rodadas[i][j + 2];
        }

        int eliminados[MAX_PARTICIPANTES] = {0};

        if (J == 1) {
            for (j = 0; j < N; j++) {
                if (acoes[j] == 0) {
                    eliminados[ fila[j] ] = 1;
                }
            }
        } else {
            for (j = 0; j < N; j++) {
                if (acoes[j] == 1) {
                    eliminados[ fila[j] ] = 1;
                }
            }
        }

        int nova_fila[MAX_PARTICIPANTES];
        int pos = 0;

        for (j = 0; j < P; j++) {
            if (!eliminados[ fila[j] ]) {
                nova_fila[pos++] = fila[j];
            }
        }

        P = pos;
        for (j = 0; j < P; j++) {
            fila[j] = nova_fila[j];
        }
    }

    return fila[0];
}

int main() {
    int teste = 1;

    while (1) {
        int P, R;
        scanf("%d %d", &P, &R);

        if (P == 0 && R == 0) {
            break;
        }

        int fila[MAX_PARTICIPANTES];
        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        int rodadas[MAX_PARTICIPANTES][MAX_PARTICIPANTES];
        for (int i = 0; i < R; i++) {
            int N;
            scanf("%d", &N);
            rodadas[i][0] = N;

            for (int j = 1; j <= N + 1; j++) {
                scanf("%d", &rodadas[i][j]);
            }
        }

        int vencedor = jogo_vivo_morto(P, R, fila, rodadas);

        printf("Teste %d\n%d\n\n", teste, vencedor);
        teste++;
    }

    return 0;
}