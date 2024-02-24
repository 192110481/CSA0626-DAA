#include <stdio.h>
int reverseNumber(int num) {
    static int reverse = 0;
    if (num == 0) 
        return 0;
    reverse = (reverse * 10) + (num % 10);
    reverseNumber(num / 10);
    return reverse;
}
int main() {
    int num, reversed;
    printf("Enter a number: ");
    scanf("%d", &num);
    reversed = reverseNumber(num);
    printf("Reverse of the number: %d\n", reversed);
    return 0;
}

