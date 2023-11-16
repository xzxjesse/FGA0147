#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    if (n<5 || n>10000){
        return 0;
    }

    int numeros[n];
    int pares[n];
    int impares[n];
    int contador_pares=0;
    int contador_impares=0;

    for(int i=0;i<n;i++){
        scanf("%d", &numeros[i]);

        if (numeros[i]<-1000000 || numeros[i]>1000000){
            return 0;
        }

        if(numeros[i]%2==0){
            pares[contador_pares++]=numeros[i];
        }else if(numeros[i]%2!=0){
            impares[contador_impares++]=numeros[i];
        }
    }

    for(int i=0;i<contador_pares;i++){
        printf("%d ", pares[i]);
    }
    printf("\n");

    for (int i=0;i<contador_impares;i++){
        printf("%d ", impares[i]);
    }
    
    return 0;
}