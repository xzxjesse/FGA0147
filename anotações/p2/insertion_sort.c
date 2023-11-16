//inserção clássica
void insertion_sort(int v[], int L, int R) {
    for (int i = L + 1; i <= R; i++) {
        for (int j = i; j > L && v[j] < v[j - 1]; j--) {
            // Troca de elementos se estiverem fora de ordem
            int temp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = temp;
        }
    }
}

// com o objetivo de minimizar o número de trocas de elementos no array
void insertion_sort_otimizado_minimizar(int v[], int L, int R) {
    int elemento, i, j;
    
    for (i = L + 1; i <= R; i++){
        elemento = v[i];
        
        // Desloca os elementos maiores para a direita sem realizar trocas imediatas
        for (j = i; j > L && elemento < v[j - 1]; j--) {
            v[j] = v[j - 1];
        }
        
        v[j] = elemento; // Coloca o elemento na posição correta
    }
}

// empurrar o menor para a esquerda e puxar os maiores para a direita
void insertion_sort_otimizado_empurrar(int v[], int L, int R) {
    int elemento, i, j;

    // Empurre o menor para a esquerda (sentinela),
    // enquanto puxa os maiores para a direita
    for (i = R; i > L; i--){
        int temp = v[L];
        v[L] = v[i];
        v[i] = temp;
    }

    // A partir do terceiro elemento
    for (i = L + 2; i <= R; i++) {
        elemento = v[i];

        // Desloca os elementos maiores para a direita sem realizar trocas imediatas
        for (j = i; elemento < v[j - 1]; j--) {
            v[j] = v[j - 1];
        }

        v[j] = elemento; // Coloca o elemento na posição correta
    }
}

//shell sort
void shell_sort(int v[], int L, int R) {
    int h = 1;

    // Determina o valor inicial de h
    while (h < (R - L + 1) / 3) {
        h = 3 * h + 1;
    }

    // Começa o loop de h-sorting, onde h é a lacuna entre elementos comparados
    while (h >= 1) {
        // Loop sobre cada subarray começando com o índice L + h
        for (int i = L + h; i <= R; i++) {
            // Insere o elemento na posição correta dentro do subarray
            for (int j = i; j >= L + h && v[j] < v[j - h]; j -= h) {
                //j -= h é o decremento com uma diferença de h
                // Troca elementos se estiverem fora de ordem
                int temp = v[j];
                v[j] = v[j - h];
                v[j - h] = temp;
            }
        }

        // Reduz o valor de h para a próxima iteração
        h = h / 3;
    }
}
