/* Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2) */

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with INF
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--; v--; // convert to 0-based

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[MAX] = {0};
    int key[MAX];

    // Initialize keys
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX;

    key[0] = 0; // start from node 0

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {

        // Find minimum key vertex not visited
        int u = -1;
        int min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}