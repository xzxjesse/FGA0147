#include <stdio.h>
#include <stdlib.h>

typedef struct info{
    int valor, indice;
} infos;

void shell_sort(infos *v, int L, int R){
    int h = 1;

    for (; h <= (R - L) / 9; h = 3 * h + 1){
        ;
    }

    for (; h > 0; h /= 3){
        for (int i = L + h; i <= (R - L); i++){
            for (int j = i; j >= L + h && v[j].valor < v[j - h].valor; j -= h){
                infos t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }
        }
    }
}

int busca_binaria(infos *v, int n, int info)
{
    int l = 0;
    int h = n;

    while (h > l){
        int meio = l + (h - l) / 2;

        if (info == v[meio].valor){
            return meio;
        }else if (info < v[meio].valor){
            h = meio;
        }else{
            l = meio + 1;
        }
    }

    return -1;
}

int main()
{
    int n, m, info;

    scanf("%d %d", &n, &m);

    infos v[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i].valor);
        v[i].indice = i;
    }

    shell_sort(v, 0, n);

    while (m--){
        scanf("%d", &info);
        
        int r =  busca_binaria(v, n, info);
        
        if (r != -1){
            printf("%d\n", v[r].indice);
        }else{
            printf("%d\n", r);
        }
    }

    return 0;
}