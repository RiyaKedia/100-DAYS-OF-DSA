/* Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node. */

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// Mapping arrays
struct Node* map[200];
struct Node* keys[200];
int size = 0;

// Find index
int findIndex(struct Node* node) {
    for (int i = 0; i < size; i++) {
        if (keys[i] == node)
            return i;
    }
    return -1;
}

// DFS clone
struct Node* dfs(struct Node* node) {
    if (node == NULL) return NULL;

    int idx = findIndex(node);
    if (idx != -1)
        return map[idx];

    struct Node* clone = malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = malloc(sizeof(struct Node*) * node->numNeighbors);

    keys[size] = node;
    map[size] = clone;
    size++;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Empty graph\n");
        return 0;
    }

    // Create nodes
    struct Node* nodes[n + 1];
    for (int i = 1; i <= n; i++) {
        nodes[i] = malloc(sizeof(struct Node));
        nodes[i]->val = i;
    }

    // Input adjacency list
    for (int i = 1; i <= n; i++) {
        int k;
        printf("Enter number of neighbors of node %d: ", i);
        scanf("%d", &k);

        nodes[i]->numNeighbors = k;
        nodes[i]->neighbors = malloc(sizeof(struct Node*) * k);

        printf("Enter neighbors: ");
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            nodes[i]->neighbors[j] = nodes[x];
        }
    }

    // Clone graph
    size = 0;
    struct Node* cloned = dfs(nodes[1]);

    // Print cloned graph (simple)
    printf("\nCloned Graph:\n");
    for (int i = 1; i <= n; i++) {
        printf("Node %d -> ", i);
        struct Node* curr = dfs(nodes[i]);  // get cloned version
        for (int j = 0; j < curr->numNeighbors; j++) {
            printf("%d ", curr->neighbors[j]->val);
        }
        printf("\n");
    }

    return 0;
}