/* Given weighted graph with non-negative edges, compute shortest path from source using priority queue. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100

// Graph Node
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAXN];

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[1000];
int heapSize = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push
void push(int v, int dist) {
    heap[heapSize].vertex = v;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Create graph node
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

// Dijkstra Algorithm
void dijkstra(int n, int src) {
    int dist[MAXN];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        HeapNode current = pop();
        int u = current.vertex;

        // Skip outdated entries
        if (current.dist > dist[u])
            continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

// Main Function
int main() {
    int n = 5;

    // Initialize adjacency list ONLY HERE
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Add edges
    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(3, 4, 1);

    // Run Dijkstra
    dijkstra(n, 0);

    return 0;
}