/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.*/

#include <stdio.h>
#include <stdlib.h>

// Function to perform Topological Sort (Kahn's Algorithm)
void findOrder(int numCourses, int prerequisites[][2], int prerequisitesSize) {
    
    // Adjacency list
    int adj[numCourses][numCourses];
    int adjSize[numCourses];

    // Initialize
    for (int i = 0; i < numCourses; i++) {
        adjSize[i] = 0;
    }

    // Indegree array
    int indegree[numCourses];
    for (int i = 0; i < numCourses; i++) {
        indegree[i] = 0;
    }

    // Build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a; // b → a
        indegree[a]++;
    }

    // Queue
    int queue[numCourses];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Result
    int result[numCourses];
    int index = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        result[index++] = node;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // Check for cycle
    if (index != numCourses) {
        printf("Cycle detected! No valid course order.\n");
        return;
    }

    // Print result
    printf("Course Order: ");
    for (int i = 0; i < numCourses; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisites: ");
    scanf("%d", &prerequisitesSize);

    int prerequisites[prerequisitesSize][2];

    printf("Enter prerequisites (a b means b -> a):\n");
    for (int i = 0; i < prerequisitesSize; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    findOrder(numCourses, prerequisites, prerequisitesSize);

    return 0;
}