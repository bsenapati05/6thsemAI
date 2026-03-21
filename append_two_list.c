#include <stdio.h>
int main() {
    int arr1[100], arr2[100], result[200];
    int n1, n2, i;
    // Input first list
    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);
    printf("Enter elements of first list:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    // Input second list
    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);
    printf("Enter elements of second list:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    // Copy first list into result
    for (i = 0; i < n1; i++) {
        result[i] = arr1[i];
    }
    // Append second list
    for (i = 0; i < n2; i++) {
        result[n1 + i] = arr2[i];
    }
    // Print result
    printf("Appended list:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
