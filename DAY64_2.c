/* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0. */

#include <stdio.h>

#define SIZE 10

typedef struct {
    int x, y;
} Node;

int orangesRotting(int grid[SIZE][SIZE], int m, int n) {
    Node queue[SIZE * SIZE];
    int front = 0, rear = 0;

    int fresh = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Count fresh & add rotten
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2)
                queue[rear++] = (Node){i, j};
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    if (fresh == 0) return 0;

    int minutes = 0;

    while (front < rear) {
        int size = rear - front;
        int infected = 0;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear++] = (Node){nx, ny};
                    fresh--;
                    infected = 1;
                }
            }
        }

        if (infected) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int m, n;
    int grid[SIZE][SIZE];

    // Take input
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter grid values (0 = empty, 1 = fresh, 2 = rotten):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Function call
    int result = orangesRotting(grid, m, n);

    // Output
    printf("Minimum minutes required: %d\n", result);

    return 0;
}