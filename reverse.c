#include <stdio.h>

// Recursive function to reverse the number
int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    else
        return reverseNumber(num / 10, rev * 10 + num % 10);
}

int main() {
    int number, reversed;

    printf("Enter an integer: ");
    scanf("%d", &number);

    reversed = reverseNumber(number, 0);
    printf("Reversed number: %d\n", reversed);

    return 0;
}
