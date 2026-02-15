/* Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements */

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum of primary diagonal
    int limit = (m < n) ? m : n;  // works for non-square matrices too
    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    // Output result
    printf("%d\n", sum);

    return 0;
}