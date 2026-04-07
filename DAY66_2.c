/*                                                                                                             There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue structure
typedef struct {
    int *data;
    int front, rear;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * size);
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

int main() {
    int numCourses, m;

    // Input number of courses and prerequisites
    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &m);

    int **prerequisites = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        prerequisites[i] = (int*)malloc(sizeof(int) * 2);
    }

    printf("Enter prerequisite pairs (a b):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    // Graph
    int **graph = (int**)malloc(sizeof(int*) * numCourses);
    int *indegree = (int*)calloc(numCourses, sizeof(int));
    int *size = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(sizeof(int) * numCourses);
    }

    // Build graph
    for (int i = 0; i < m; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][size[b]++] = a;
        indegree[a]++;
    }

    // Queue
    Queue* q = createQueue(numCourses);

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            enqueue(q, i);
        }
    }

    int count = 0;

    while (!isEmpty(q)) {
        int node = dequeue(q);
        count++;

        for (int i = 0; i < size[node]; i++) {
            int neighbor = graph[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                enqueue(q, neighbor);
            }
        }
    }

    if (count == numCourses)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}