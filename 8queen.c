#include <stdio.h>

#define N 8

int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if placing a queen at (row, col) is safe
int isSafe(int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Solve the problem using backtracking
int solve(int col) {
    if (col >= N)
        return 1; // All queens placed

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1; // Place queen

            if (solve(col + 1))
                return 1;

            board[i][col] = 0; // Backtrack
        }
    }

    return 0; // No place for queen
}

int main() {
    // Initialize board to 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solve(0)) {
        printf("One solution for the 8-Queens problem:\n");
        printBoard();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
