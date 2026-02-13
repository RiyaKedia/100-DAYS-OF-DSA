/* Given an m x n matrix, return all elements of the matrix in spiral order. */

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int m, int n, int* returnSize) {
    int *result = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        // Top row
        for (int i = left; i <= right; i++)
            result[k++] = matrix[top][i];
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;

        // Bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[k++] = matrix[bottom][i];
            bottom--;
        }

        // Left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }

    return result;
}

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int **matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int *result = spiralOrder(matrix, m, n, &returnSize);  // <-- FIXED LINE

    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free memory
    free(result);
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}