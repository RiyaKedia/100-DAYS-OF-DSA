/* Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

 

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 

Constraints:
1 ≤ V ≤ 105 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int timer;

void dfs(int u, int V, int adj[MAX][MAX],
         int visited[], int disc[], int low[],
         int parent[], int ap[]) {

    visited[u] = 1;
    disc[u] = low[u] = timer++;
    int children = 0;

    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;

                dfs(v, V, adj, visited, disc, low, parent, ap);

                if (low[v] < low[u])
                    low[u] = low[v];

                // Root node
                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                // Non-root node
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }
            else if (v != parent[u]) {
                if (disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}

int main() {
    int V, E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};

    printf("Enter edges:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int visited[MAX] = {0};
    int disc[MAX], low[MAX], parent[MAX], ap[MAX] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, V, adj, visited, disc, low, parent, ap);
    }

    int found = 0;
    printf("Articulation points: ");

    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    return 0;
}