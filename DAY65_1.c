/* Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// DFS with parent tracking
bool dfs(int node, int parent, struct Node* adj[], bool visited[]) {
    visited[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle detected
        }

        temp = temp->next;
    }
    return false;
}

// Check cycle in all components
bool isCycle(int V, struct Node* adj[]) {
    bool visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

// MAIN (User Input)
int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}