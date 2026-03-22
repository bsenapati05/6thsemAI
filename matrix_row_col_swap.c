#include <stdio.h>
int main() {
    int rows, cols, i, j;
    int matrix[10][10], transpose[10][10];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input the matrix
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Logic: Interchange rows and columns
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    // Display the Result
    printf("\nTranspose of the matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d  ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
