// ordenação Quick Sort
void quick_sort(int *v, int L, int R) {
    // Condição de parada: se o índice direito (R) é menor ou igual ao índice esquerdo (L)
    if (R <= L) {
        return;
    }

    // Realiza a partição e obtém o índice do pivô
    int p = partitionR(v, L, R);

    // Chama recursivamente o Quick Sort para as partições à esquerda e à direita do pivô
    quick_sort(v, L, p - 1);
    quick_sort(v, p + 1, R);
}

// partição utilizando o pivô na extrema direita (partition Right)
int partitionR(int *v, int L, int R) {
    // Índices para percorrer os elementos do array
    int i = L - 1;
    int j = R;
    // Escolhe o pivô como o elemento mais à direita
    int pivo = v[R];

    // Loop para encontrar a posição correta do pivô no array
    while (i < j) {
        while (v[++i] < pivo);
        while (v[--j] >= pivo && j > L);
        if (i < j) {
            // Troca os elementos encontrados fora de posição
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    int temp = v[i];
    v[i] = v[R];
    v[R] = temp;

    // Retorna a posição final do pivô
    return i;
}

// partição utilizando o pivô na extrema esquerda (partition Left)
int partitionL(int *v, int L, int R) {
    // Índices para percorrer os elementos do array
    int i = L;
    int j = R + 1;
    // Escolhe o pivô como o elemento mais à esquerda
    int pivo = v[L];

    // Loop para encontrar a posição correta do pivô no array
    while (1) {
        while (v[++i] < pivo) {
            if (i == R) {
                break;
            }
        }
        while (pivo < v[--j]) {
            if (j == L) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        // Troca os elementos encontrados fora de posição
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    // Coloca o pivô na posição correta
    int temp = v[L];
    v[L] = v[j];
    v[j] = temp;

    // Retorna a posição final do pivô
    return j;
}

// partição utilizando o pivô na extrema direita (partition com otimização de cópia de elementos)
int partitionCORMEM(int *v, int L, int R) {
    // Escolhe o pivô como o elemento mais à direita
    int pivo = v[R];
    int j = L;
    int i = L;

    // Loop para rearranjar os elementos menores que o pivô à esquerda
    while (i < R) {
        if (less(v[i], pivo)) {
            // Troca os elementos menores que o pivô para a parte esquerda do array
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;

            j++; // Incrementa o índice da partição
        }
        i++; // Incrementa o índice do array
    }

    // Coloca o pivô na posição correta
    int temp = v[R];
    v[R] = v[j];
    v[j] = temp;

    // Retorna a posição final do pivô
    return j;
}

// Função para encontrar a mediana de três
int mediana_de_tres(int *v, int a, int b, int c) {
    if (v[a] < v[b]) {
        if (v[b] < v[c]) {
            return b; // b é a mediana
        } else if (v[a] < v[c]) {
            return c; // c é a mediana
        } else {
            return a; // a é a mediana
        }
    } else {
        if (v[c] < v[b]) {
            return b; // b é a mediana
        } else if (v[c] < v[a]) {
            return c; // c é a mediana
        } else {
            return a; // a é a mediana
        }
    }
}

// partição utilizando a mediana de três
int particao_mediana_de_tres(int *v, int L, int R) {
    // Escolhe os índices dos três elementos para calcular a mediana
    int m = (L + R) / 2;
    int indice_mediana = mediana_de_tres(v, L, m, R);

    // Coloca o pivô na posição correta
    int temp = v[indice_mediana];
    v[indice_mediana] = v[R];
    v[R] = temp;

    // Utiliza a partição padrão para rearranjar os elementos
    int i = L - 1;
    int pivo = v[R];
    for (int j = L; j < R; j++) {
        if (v[j] <= pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    // Coloca o pivô na posição correta após a partição
    temp = v[i + 1];
    v[i + 1] = v[R];
    v[R] = temp;

    // Retorna o índice final do pivô
    return i + 1;
}