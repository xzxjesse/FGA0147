#include <stdio.h>

int main(){

    int N;
    int i;

    scanf("%d", &N);

    for (i = 1; i <= N; i++){
        if(i%2==1){
            printf("THUMS THUMS THUMS\n");
        } else if (i%2==0){
            printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
        }
    }

    return 0;
}