// merge sort
void merge_sort(int *v, int L, int R) {
    // Condição de parada: se L é maior ou igual a R, o array tem no máximo um elemento
    if (L >= R) {
        return;
    }

    // Calcula o ponto médio do array
    int m = (R + L) / 2;

    // Chama recursivamente merge_sort para as metades esquerda e direita do array
    merge_sort(v, L, m);
    merge_sort(v, m + 1, R);

    // Combina as duas metades ordenadas usando a função merge
    merge(v, L, m, R);
}


// Função para combinar duas metades ordenadas de um array
void merge(int *v, int L, int m, int R) {
    // Calcula o tamanho do array resultante
    int tam = R + 1 - L;

    // Aloca espaço para um array auxiliar
    int *aux = malloc(sizeof(int) * tam);

    // Inicializa índices para percorrer as duas metades e o array auxiliar
    int i = L;      // Início do subarray esquerdo
    int j = m + 1;  // Início do subarray direito
    int k = 0;      // Índice do array auxiliar

    // Combina os subarrays ordenados
    while (i <= m && j <= R) {  // Percorre os subarrays
        if (v[i] <= v[j])        // Testa os elementos dos subarrays
            aux[k++] = v[i++];   // Adiciona o elemento do subarray esquerdo ao auxiliar
        else
            aux[k++] = v[j++];   // Adiciona o elemento do subarray direito ao auxiliar
    }

    // Ainda há elementos no sub-vetor esquerdo?
    while (i <= m)
        aux[k++] = v[i++];

    // Ainda há elementos no sub-vetor direito?
    while (j <= R)
        aux[k++] = v[j++];

    // Reinicializa o índice do array auxiliar
    k = 0;

    // Copia os elementos ordenados de volta para o array original v
    for (i = L; i <= R; i++)
        v[i] = aux[k++];

    // Libera a memória alocada para o array auxiliar
    free(aux);
}

// Merge Sort Bottom-Up

/*
sz (size)
lo (índice inferior)
hi (índice superior)
*/
void merge_sort_bu(int *v, int L, int R) {
    // Calcula o tamanho do array a ser ordenado
    int tamanho = R - L + 1;

    // Loop externo controla o tamanho dos subarrays (sz)
    for (int sz = 1; sz < tamanho; sz = 2 * sz) {
        // Loop interno percorre os subarrays e realiza o merge
        for (int lo = 0; lo < tamanho - sz; lo += 2 * sz) {
            // Calcula o índice do final do subarray atual
            int hi = lo + 2 * sz - 1;

            // Verifica se hi ultrapassa o limite do array
            if (hi > tamanho - 1) {
                hi = tamanho - 1;
            }

            // Chama a função merge para combinar os subarrays
            merge(v, lo, lo + sz - 1, hi);
        }
    }
}
