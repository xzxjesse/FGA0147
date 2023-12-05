#include <stdio.h>
#include <stdlib.h>

typedef struct candidato{
    int votos, digitos;
} candidato;

void merge(candidato *v, int L, int m, int R){
    candidato *auxiliar = malloc(sizeof(candidato) * (R - L));

    int i = L, j = m, k = 0;

    while (i < m && j < R){
        auxiliar[k++] = v[i].votos <= v[j].votos ? v[i++] : v[j++];
    }
    while (i < m){
        auxiliar[k++] = v[i++];
    }
    while (j < R){
        auxiliar[k++] = v[j++];
    }

    for (i = L; i < R; i++){
        v[i] = auxiliar[i - L];
    }

    free(auxiliar);
}

void merge_sort(candidato *v, int L, int R){
    if (R - 1 <= L){
        return;
    }

    int meio = L + (R - L) / 2;

    merge_sort(v, L, meio);
    merge_sort(v, meio, R);
    merge(v, L, meio, R);
}

int main(){
    candidato *vetor = malloc(sizeof(candidato) * 100001);
    int S, F, E, voto, votos_validos = 0, votos_invalidos = 0;
    int votos_totais = 0;

    scanf("%d %d %d", &S, &F, &E);

    for (int i = 10; i < 100000; i++){
        vetor[i].digitos = i;
    }

    while (scanf("%d", &voto) != EOF){
        if (voto >= 10){
            votos_validos++;
            vetor[voto].votos++;
        }else{
            votos_invalidos++;
        }

    for (int i = 0, m = 10; i < 4; i++, m *= 10){
        merge_sort(vetor, m, m * 10);
    }

    for (int i = 99; i >= 10; i--){
        votos_totais += vetor[i].votos;
    }

    printf("%d %d\n", votos_validos, votos_invalidos);

    int percentual = (float)vetor[99].votos / (float)votos_totais >= 0.51 ? 1 : 0;

    if (percentual){
        printf("%d\n", vetor[99].digitos);
    }else{
        printf("Segundo turno\n");
    }

    for (int i = 999; S; i--, S--){
        printf("%d ", vetor[i].digitos);
    }
    printf("\n");

    for (int i = 9999; F; i--, F--){
        printf("%d ", vetor[i].digitos);
    }
    printf("\n");

    for (int i = 99999; E; i--, E--){
        printf("%d ", vetor[i].digitos);
    }
    printf("\n");

    printf("\n");
    
    return 0;
}