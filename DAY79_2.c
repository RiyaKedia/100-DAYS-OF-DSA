/* Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
Constraints:
1 ≤ V ≤ 106
0 ≤ E ≤ 106
0 ≤ edges[i][0], edges[i][1] < V

 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100000

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adj;
};

// Stack
int stack[MAX];
int top = -1;

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// DFS 1 (fill stack)
void dfs1(int v, bool visited[], struct Graph* graph) {
    visited[v] = true;
    
    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs1(temp->data, visited, graph);
        temp = temp->next;
    }
    
    push(v);
}

// DFS 2 (on reversed graph)
void dfs2(int v, bool visited[], struct Graph* graph) {
    visited[v] = true;
    
    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs2(temp->data, visited, graph);
        temp = temp->next;
    }
}

// Reverse graph
struct Graph* reverseGraph(struct Graph* graph) {
    struct Graph* rev = createGraph(graph->V);
    
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            addEdge(rev, temp->data, i);
            temp = temp->next;
        }
    }
    
    return rev;
}

// Kosaraju Algorithm
int kosaraju(struct Graph* graph) {
    bool visited[MAX] = {false};
    
    // Step 1: Fill stack
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            dfs1(i, visited, graph);
    }
    
    // Step 2: Reverse graph
    struct Graph* rev = reverseGraph(graph);
    
    // Step 3: DFS using stack
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    
    int scc = 0;
    
    while (top != -1) {
        int v = pop();
        
        if (!visited[v]) {
            dfs2(v, visited, rev);
            scc++;
        }
    }
    
    return scc;
}

// Main function
int main() {
    int V, E;
    
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);
    
    struct Graph* graph = createGraph(V);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    
    int result = kosaraju(graph);
    
    printf("Number of Strongly Connected Components: %d\n", result);
    
    return 0;
}