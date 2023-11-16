void bubble_sort(int v[], int L, int R) {
    for (; R > L; R--) {
        for (int j = L; j < R; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
