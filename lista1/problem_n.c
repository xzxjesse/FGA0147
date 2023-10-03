#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    if (n<5 || n>10000){
        return 0;
    }

    int numeros[n];

    for(int i=0;i<n;i++){
        scanf("%d", &numeros[i]);

        if (numeros[i]<-1000000 || numeros[i]>1000000){
            return 0;
        }
    }

    int teste;
    int pertencimento=0;

    scanf("%d", &teste);

    for(int i=1;i<n;i++){
        if(numeros[i]==teste){
            pertencimento=1;
            break;
        }
    }

    if(pertencimento==1){
        printf("pertence");
    }else if(pertencimento==0){
        printf("nao pertence");
    }

    return 0;
}