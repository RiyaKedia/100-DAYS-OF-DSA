/* Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm). */

#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    int indegree[MAX] = {0};

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) {
                indegree[j]++;   // calculate indegree
            }
        }
    }

    // Step 1: Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX], index = 0;

    // Step 2: Process queue
    while (!isEmpty()) {
        int u = dequeue();
        topo[index++] = u;

        // Reduce indegree of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // Step 3: Check for cycle
    if (index != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}