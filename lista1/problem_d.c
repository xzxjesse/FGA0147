#include <stdio.h>

int main() {
    int aLargura, bComprimento, cAltura, xLargura, yComprimento, zAltura;
    int largura, comprimento, altura;
    int quantidade = 0;

    scanf("%d %d %d", &aLargura, &bComprimento, &cAltura);
    scanf("%d %d %d", &xLargura, &yComprimento, &zAltura);
    
    if (aLargura >= 0 && aLargura <= 1000000 && bComprimento >= 0 && bComprimento <= 1000000 && cAltura >= 0 && cAltura <= 1000000 && xLargura >= 0 && xLargura <= 1000000 && yComprimento >= 0 && yComprimento <= 1000000 && zAltura >= 0 && zAltura <= 1000000 && quantidade <= 1000000){

        if (xLargura>=aLargura && yComprimento>=bComprimento && zAltura>=cAltura){
            largura = xLargura/aLargura;
            comprimento = yComprimento/bComprimento;
            altura = zAltura/cAltura;

            quantidade = largura*comprimento*altura;
        }
        
    }
        
    printf("%d\n", quantidade);

    return 0;
}