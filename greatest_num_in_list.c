#include <stdio.h>

int main() {
    int arr[100], n, i, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is maximum
    max = arr[0];

    // Find greatest number
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Greatest number = %d\n", max);

    return 0;
}
