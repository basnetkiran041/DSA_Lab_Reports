#include <stdio.h>

// Recursive function to check for prime
int isPrime(int num, int i) {
    if (num <= 1)
        return 0;  // 0 and 1 are not prime
    if (i == 1)
        return 1;  // No divisors found; prime
    if (num % i == 0)
        return 0;  // Divisible; not prime
    return isPrime(num, i - 1);  // Check next divisor
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPrime(number, number / 2))
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);

    return 0;
}
