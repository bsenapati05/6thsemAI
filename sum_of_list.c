#include <stdio.h>

int main() {
    int arr[100], n, i;
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of elements = %d\n", sum);

    return 0;
}
