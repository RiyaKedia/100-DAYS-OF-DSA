/* In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected. */

#include <stdio.h>

#define MAXN 1001

int parent[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // path compression
    return parent[x];
}

void findRedundantConnection(int edges[][2], int n) {
    
    // Initialize DSU
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(u);
        int pv = find(v);

        // Cycle detected
        if (pu == pv) {
            printf("Redundant Edge: [%d, %d]\n", u, v);
            return;
        }

        parent[pu] = pv;
    }

    printf("No redundant edge found\n");
}

int main() {
    int n;

    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    findRedundantConnection(edges, n);

    return 0;
}