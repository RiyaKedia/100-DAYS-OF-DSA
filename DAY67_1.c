/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    // Push to stack after visiting all neighbors
    stack[++top] = node;
}

// Topological Sort using DFS
void topoSort(int n) {
    // Initialize visited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Call DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v means u -> v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(n);

    return 0;
}