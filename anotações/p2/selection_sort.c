void selection_sort(int v[], int L, int R) {
    int menor;

    for (int i = L; i < R; i++) {
        menor = i;

        for (int j = i + 1; j <= R; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (i != menor) {
            int temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}
