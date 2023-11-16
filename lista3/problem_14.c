#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int andar;
    int pressionamentos;
} Estado;

int minPressionamentosBotao(int andares, int inicio, int objetivo, int cima, int baixo) {
    bool *visitado = (bool *)malloc((andares + 1) * sizeof(bool));
    for (int i = 1; i <= andares; i++) {
        visitado[i] = false;
    }

    Estado *fila = (Estado *)malloc((andares + 1) * sizeof(Estado));
    int frente = 0;
    int tras = 0;

    fila[tras].andar = inicio;
    fila[tras].pressionamentos = 0;
    tras++;

    while (frente < tras) {
        Estado atual = fila[frente++];
        int andarAtual = atual.andar;
        int pressionamentosAtuais = atual.pressionamentos;

        if (andarAtual == objetivo) {
            free(visitado);
            free(fila);
            return pressionamentosAtuais;
        }

        int proximoAndarCima = andarAtual + cima;
        int proximoAndarDown = andarAtual - baixo;

        if (proximoAndarCima <= andares && !visitado[proximoAndarCima]) {
            visitado[proximoAndarCima] = true;
            fila[tras].andar = proximoAndarCima;
            fila[tras].pressionamentos = pressionamentosAtuais + 1;
            tras++;
        }

        if (proximoAndarDown >= 1 && !visitado[proximoAndarDown]) {
            visitado[proximoAndarDown] = true;
            fila[tras].andar = proximoAndarDown;
            fila[tras].pressionamentos = pressionamentosAtuais + 1;
            tras++;
        }
    }

    free(visitado);
    free(fila);

    return -1;
}

int main() {
    int andares, inicio, objetivo, cima, baixo;
    scanf("%d %d %d %d %d", &andares, &inicio, &objetivo, &cima, &baixo);

    int resultado = minPressionamentosBotao(andares, inicio, objetivo, cima, baixo);

    if (resultado == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", resultado);
    }

    return 0;
}
