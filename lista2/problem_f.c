long int fibonacci(int n) {
    static long int memo[81];

    if (n < 1 || n > 80) {
        exit(1);
    }

    if (n <= 2) {
        return 1;
    }

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memo[n];
}
