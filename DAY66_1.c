/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int **graph, int *visited, int *recStack, int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, recStack, n))
                    return true;
            }
            else if (recStack[i]) {
                return true; // cycle found
            }
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create adjacency matrix
    int **graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    int *visited = (int*)calloc(n, sizeof(int));
    int *recStack = (int*)calloc(n, sizeof(int));

    // Check for cycle
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}