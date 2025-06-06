#include <stdio.h>

// Recursive function to calculate Fibonacci number at position n
int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int limit, i = 0, fib;

    printf("Enter a number (upper limit): ");
    scanf("%d", &limit);

    printf("Fibonacci series up to %d:\n", limit);
    while (1) {
        fib = fibonacci(i);
        if (fib > limit)
            break;
        printf("%d ", fib);
        i++;
    }

    return 0;
}
