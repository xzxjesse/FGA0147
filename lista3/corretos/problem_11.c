#include <stdio.h>

#define TAMANHO_MINIMO 30
#define TAMANHO_MAXIMO 60

int main() {
    int contagem_pares[TAMANHO_MAXIMO - TAMANHO_MINIMO + 1][2] = {{0}};  // Inicializa a matriz de contagem de pares
    int tamanho, resultado = 0;
    char pe;

    while (scanf("%d %c", &tamanho, &pe) != EOF) {
        if (tamanho >= TAMANHO_MINIMO && tamanho <= TAMANHO_MAXIMO) {
            if (pe == 'D') {
                contagem_pares[tamanho - TAMANHO_MINIMO][0]++;
            } else if (pe == 'E') {
                contagem_pares[tamanho - TAMANHO_MINIMO][1]++;
            }
        }
    }

    for (int i = 0; i <= TAMANHO_MAXIMO - TAMANHO_MINIMO; i++) {
        resultado += (contagem_pares[i][0] < contagem_pares[i][1]) ? contagem_pares[i][0] : contagem_pares[i][1];
    }

    printf("%d\n", resultado);

    return 0;
}
