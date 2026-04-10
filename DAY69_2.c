/* You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.) */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 101   // renamed to avoid conflict

typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAXN];

// Create node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
int networkDelayTime(int times[][3], int timesSize, int n, int k) {

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    // Build graph
    for (int i = 0; i < timesSize; i++) {
        addEdge(times[i][0], times[i][1], times[i][2]);
    }

    int dist[MAXN];
    int visited[MAXN] = {0};

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[k] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1, minDist = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            temp = temp->next;
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}

// ✅ MAIN FUNCTION (for VS Code)
int main() {
    int n, m, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int times[m][3];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &times[i][0], &times[i][1], &times[i][2]);
    }

    printf("Enter source node k: ");
    scanf("%d", &k);

    int result = networkDelayTime(times, m, n, k);

    printf("Minimum time: %d\n", result);

    return 0;
}