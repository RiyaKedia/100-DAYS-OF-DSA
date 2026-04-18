/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* adjSize) {
    visited[node] = 1;
    
    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, visited, adj, adjSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate adjacency list
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adjSize = (int*)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Visited array
    int* visited = (int*)calloc((n + 1), sizeof(int));

    // Run DFS from node 1
    dfs(1, visited, adj, adjSize);

    // Check if all nodes visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}