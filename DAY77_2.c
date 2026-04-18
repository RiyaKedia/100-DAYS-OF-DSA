/*                                                                                                         There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.*/

#include <stdio.h>
#include <stdlib.h>

int timeCounter;

// DFS function
void dfs(int u, int parent, int* disc, int* low,
         int** adj, int* adjSize,
         int result[][2], int* returnSize) {
    
    disc[u] = low[u] = timeCounter++;
    
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        
        if (v == parent) continue;
        
        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize);
            
            if (low[v] < low[u])
                low[u] = low[v];
            
            // Bridge condition
            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    
    printf("Enter number of servers (nodes): ");
    scanf("%d", &n);
    
    printf("Enter number of connections (edges): ");
    scanf("%d", &m);
    
    int connections[m][2];
    
    printf("Enter connections (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &connections[i][0], &connections[i][1]);
    }
    
    // Step 1: Count degrees
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < m; i++) {
        degree[connections[i][0]]++;
        degree[connections[i][1]]++;
    }
    
    // Step 2: Allocate adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }
    
    // Step 3: Fill adjacency list
    for (int i = 0; i < m; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }
    
    // Step 4: Initialize arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    
    int result[m][2];
    int returnSize = 0;
    
    timeCounter = 0;
    
    // Step 5: Run DFS
    dfs(0, -1, disc, low, adj, adjSize, result, &returnSize);
    
    // Step 6: Output
    printf("\nCritical Connections:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }
    
    return 0;
}