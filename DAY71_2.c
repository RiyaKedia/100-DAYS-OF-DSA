/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate minimum cost using Prim's Algorithm
int minCostConnectPoints(int points[][2], int n) {
    int minDist[n];
    int visited[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = 0;
    }

    minDist[0] = 0; // Start from first point
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Find unvisited node with minimum distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    return totalCost;
}

int main() {
    int n;

    // Input number of points
    printf("Enter number of points: ");
    scanf("%d", &n);

    int points[n][2];

    // Input points
    printf("Enter coordinates (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = minCostConnectPoints(points, n);

    printf("Minimum cost to connect all points: %d\n", result);

    return 0;
}