#include <stdio.h>
void printMinMaxSequence(int arr[], int size) {
    if (size == 0) {
        printf("The list is empty.\n");
        return;
    }
    int min = arr[0];
    int max = arr[0];
    printf("Minimum and maximum value sequence:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            printf("Minimum: %d, Maximum: %d\n", min, max);
        } else if (arr[i] > max) {
            max = arr[i];
            printf("Minimum: %d, Maximum: %d\n", min, max);
        }
    }
}
int main() {
    int size;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original list:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printMinMaxSequence(arr, size);
    return 0;
}
