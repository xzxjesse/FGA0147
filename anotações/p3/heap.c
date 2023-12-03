#include <stdlib.h>

typedef struct {
    int chave;
} Item;

static Item *pq;
static int N;

// Defina as funções/macro necessárias aqui
#define less(a, b) ((pq[a].chave) < (pq[b].chave))
#define exch(a, b) do { Item t = pq[a]; pq[a] = pq[b]; pq[b] = t; } while (0)

// Inicialização
void PQinit(int maxN){
    pq = malloc(sizeof(Item) * (maxN + 1));
    N = 0;
}

// Verifica se está vazio
int PQempty(){
    return N == 0;
}

// Fixa a propriedade de heap após inserção
void fixUp(int k){
    while (k > 1 && less(k/2, k)){
        exch(k, k/2);
        k = k/2;
    }
}

// Insere um elemento na fila de prioridade
void PQinsert(Item v){
    pq[++N] = v;
    fixUp(N);
}

// Fixa a propriedade de heap após remoção
void fixDown(int k, int N){
    int j;

    while(2*k <= N){
        j = 2*k;

        if(j < N && less(j, j+1)){
            j++;
        }

        if(!less(k, j)){
            break;
        }

        exch(k, j);
        k = j;
    }
}

// Remove um elemento na fila de prioridade
Item PQdelmax(){
    exch(1, N);
    fixDown(1, N-1);
    return pq[N--];
}

// Alteração de prioridade com índice na fila
void PQchange(int i, int valor){
    int chaveAnterior = pq[i].chave;  // Salva a chave anterior para comparação
    pq[i].chave = valor;

    if (valor > chaveAnterior) {
        fixUp(i);
    } else {
        fixDown(i, N);
    }
}

// Função para trocar dois elementos na fila e atualizar os índices
void troca(int a, int b) {
    // Atualiza a fila de prioridades
    exch(a, b);
}

// Heap Sort
void PQsort(Item *v, int L, int R){
    PQinit(R - L + 1);

    // Insere os elementos no Heap
    for(int k = L; k <= R; k++){
        PQinsert(v[k]);
    }

    // Remove os elementos ordenados do Heap
    for(int k = R; k >= L; k--){
        v[k] = PQdelmax();
    }
}

void heap_sort(Item *v, int l, int r) {
    pq = v + l - 1;
    N = r - l + 1;

    // Constrói o heap bottom-up
    for (int k = N / 2; k >= 1; k--) {
        fixDown(k, N);
    }

    // Ordena o array
    while (N > 1) {
        exch(1, N);
        fixDown(1, --N);
    }
}

// Intro sort
void intro (int *v , int L , int R , int maxdepth ) {
    if(R-L <=15) {
    // insertion_sort (v, l, r);
    return ;
    } else if( maxdepth == 0) {
        // merge_sort (v, l, r);
        heap_sort (v, L, R) ;
    } else {
        compexch (v[L], v[(L+R)/2]) ;
        compexch (v[L], v[R]) ;
        compexch (v[R], v[(L+R)/2]) ;

        int p = partition (v , L , R ) ;
        intro (v, L, p-1, maxdepth-1) ;
        intro (v, p+1, R, maxdepth-1) ;
    }
}

void intro_sort (int *v , int L , int R ){
    // duas vezes a altura da á rvore
    int maxdepth = 2*((int)log2((double)(R-L+1)));

    intro (v, L, R, maxdepth);
    insertion_sort (v ,L , R);
}
