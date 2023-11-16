#include <stdio.h>

int main() {
    int A, V;
    int i, x, y;
    int aeroportos[101] = {0};
    int teste = 1;

    while (1) {
        scanf("%d %d", &A, &V);

        if (A == 0 && V == 0) {
            break;
        }

        for (i = 1; i <= A; i++) {
            aeroportos[i] = 0;
        }

        for (i = 0; i < V; i++) {
            scanf("%d %d", &x, &y);
            aeroportos[x]++;
            aeroportos[y]++;
        }

        int max_trafego = 0;
        for (i = 1; i <= A; i++) {
            if (aeroportos[i] > max_trafego) {
                max_trafego = aeroportos[i];
            }
        }

        printf("Teste %d\n", teste++);
        for (i = 1; i <= A; i++) {
            if (aeroportos[i] == max_trafego) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
    }

    return 0;
}
