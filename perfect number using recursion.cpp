#include <stdio.h>
int sumOfDivisors(int num, int divisor) {
    if (divisor == 1)
        return 1;
    if (num % divisor == 0)
        return divisor + sumOfDivisors(num, divisor - 1);
    else
        return sumOfDivisors(num, divisor - 1);
}
int isPerfectNumber(int num) {
    int divisorSum = sumOfDivisors(num, num / 2);
    return (divisorSum == num) ? 1 : 0;
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (isPerfectNumber(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

    return 0;
}

