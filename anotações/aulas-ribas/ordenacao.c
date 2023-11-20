#include <stdio.h>
#include <stdlib.h>

typedef int item;

// Macro para obter a chave de um item
#define Key(A) (A)

// Função para verificar se o item A é menor que o item B
#define less(A, B) (Key(A) < Key(B))

// Macro para trocar os valores de A e B
#define exch(A, B) { item t = A; A = B; B = t; }

// Macro para comparar e trocar os valores de A e B, se necessário
#define cmpexch(A, B) if (less(B, A)) exch(A, B)

// Selection sort
void selection_sort (item *v, int L, int R){
    int min = L;
    for (int j = L+1; j <= R; j++){
        if (less(v[j], v[min])){
            min = j;
        }
    }
    exch(v[min],v[L]);
    selection_sort(v, L+1, R);
}

// Bubble sort
void bubble_sort (item *v, int L, int R){
    for(int i=L; i < R; i++){
        for (int j = L; j < R; j++){
            if( less(v[j+1], v[j])){
                exch(v[j+1], v[j]);
            }
        }
    }
}

void bubble_sort_direto (item *v, int L, int R){
    for(int i=L; i < R; i++){
        for (int j = L; j < R; j++){
            cmpexch(v[j], v[j+1]);
        }
    }
}

//aproveitar a ordenação
void bubble_sort_melhorado (item *v, int L, int R) {
    int troca;
    
    for (int i = L; i < R; i++) {
        troca = 0;  // Inicializa a variável de controle de trocas
        for (int j = L; j < R - i - 1; j++) {
            cmpexch(v[j], v[j + 1]);
                troca = 1;  // Indica que ocorreu uma troca
        }
        if (!troca) {
            break;  // Se não houve troca, interrompe o loop externo
        }
    }
}

// Insertion sort
void insertion_sort (item *v, int L, int R) {
    for (int i = L + 1; i <= R; i++){
        for (int j = i; j > L; j--){
            cmpexch(v[j], v[j+1]);
        }
    }
}

// evita trocas e comparações desnecessarias, abre espaço e insere
void insertion_sort_otimizado (item *v, int L, int R) {
    for (int i = R; i > L; i--){
        cmpexch(v[i], v[i-1]); //mais leve sobe
    }

    for (int i = L + 2; i <= R; i++){
        int j = i;
        item tmp = v[j];
        while (less(tmp, v[j-1])){
            v[j]=v[j-1];
            j--;
        }
        v[j]=tmp;
    }
}

// Shell sort
void insertion_sort_h (item *v, int L, int R, int h) {
    for (int i = L + h; i <= R; i++){
        int j = i;
        item tmp = v[i];
        while (j >= L + h && less(tmp, v[j-h])){
            v[j]=v[j - h];
            j-=h; //j=j-h
        }
        v[j]=tmp; 
    }
}

void shell_sort (item *v, int L, int R) {
    int h;
    for(h = 1 ; h <= (R-L)/9; h=3*h+1){
    }

    for(; h > 0; h=h/3){
        insertion_sort_h(v, L, R, h);
    }
}

// Quick sort

//muita memoria
int separa (item *v, int L, int R) {
    int tam= R - L + 1;
    item pivo = v[R];
    item *menores = malloc(sizeof(item)*tam);
    item *maiores = malloc(sizeof(item)*tam);
    int i_menor = 0;
    int i_maior = 0;
    for (int i = L; i < R; i++){
        if less(v[i],pivo){
            menores[i_menor++]=v[i];
        }else{
            maiores[i_maior++]=v[i];
        }
    }
    int i = L;
    for(int j = 0; j < i_menor; j++){
        v[i++] = menores [j];
    }
    v[i]=pivo;
    int pivo_pos = i;
    i++;
    for(int j = 0; j < i_maior; j++){
        v[i++] = maiores [j];
    }
    free(menores);
    free(maiores);
    return pivo_pos;
}

int separa_melhorado (item *v, int L, int R) {
    item pivo = v[R];
    int j = L;
    for (int k = L; k < R; k++){
        if(less(v[k], pivo)){
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[R]);
    return j;
}

// Sedgwick
int separa_sedgwick (item *v, int L, int R) {
    int i = L - 1;
    int j = R;
    item pivo = v[R];
    for(;;){
        while(less(v[++i], pivo));
        while(less(pivo, v[--j])){
            if(j==L){
                break;
            }
        }
        if(i >= j){
            break;
        }
        exch(v[i], v[j]);
    }
    exch(v[i], v[R]);
    return i;
}

void quick_sort (item *v, int L, int R){
    int j;
    j = separa_melhorado(v, L, R);
    if(R<=L){
        return;
    }
    quick_sort(v, L, j-1);
    quick_sort(v, j+1, R);
}

//mediana de três
void quick_sort_medianda (item *v, int L, int R){
    int j;
    j = separa_melhorado(v, L, R);
    if(R<=L){
        return;
    }
    cmpexch(v[(L+R)/2], v[R]);
    cmpexch(v[L], v[(L+R)/2]);
    cmpexch(v[R], v[(L+R)/2]);
    quick_sort(v, L, j-1);
    quick_sort(v, j+1, R);
}

void merge (item *v, int L, int M, int R){
    item *v2 = malloc(sizeof(item)*(R-L+1));
    int k = 0;
    int i = L;
    int j = M + 1;
    while(i <= M && j <= R){
        if(less(v[i], v[j])){
            v2[k++] = v[i++];
        }else{
            v2[k++] = v[j++];
        }
    }
    while(i <= M){
        v2[k++] = v[i++];
    }
    while(j <= R){
        v2[k++] = v[j++];
    }
    k=0;
    for(i = L; i <= R; i++){
        v[i] = v2[k++];
    }
    free(v2);
}

void merge_sort (item *v, int L, int R){
    if(L >= R){
        return;
    }
    int M = (R+L)/2;
    merge_sort(v, L, M);
    merge_sort(v, M+1, R);
    merge(v, L, M, R);
}

// main
int main(void) {
    item vetor[1000];
    for (int i = 0; i < 1000; i++){
        vetor[i] = rand();
    }

    selection_sort(vetor, 0, 999);
    bubble_sort(vetor, 0, 999);
    bubble_sort_direto(vetor, 0, 999);
    bubble_sort_melhorado(vetor, 0, 999);
    insertion_sort(vetor, 0, 999);
    insertion_sort_otimizado(vetor, 0, 999);
    shell_sort(vetor, 0, 999);
    quick_sort(vetor, 0, 999);
    merge_sort(vetor, 0, 999);
    
    return 0;
}