/* Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements. */

#include <stdio.h>
#include <stdbool.h>

bool isToeplitzMatrix(int matrix[][20], int rows, int cols) {
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[20][20];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isToeplitzMatrix(matrix, rows, cols)) {
        printf("True - It is a Toeplitz Matrix\n");
    } else {
        printf("False - It is NOT a Toeplitz Matrix\n");
    }

    return 0;
}