/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000*/

#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]\n");
        return;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("[\n");

    while (!isEmpty(&q)) {
        int size = q.rear - q.front; // number of nodes in current level

        printf("  [");
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            printf("%d", node->val);

            if (i < size - 1) printf(", ");

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
        printf("]\n");
    }

    printf("]\n");
}

// Helper function to create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Example usage
int main() {
    // Example 1: [3,9,20,null,null,15,7]

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    levelOrder(root);

    return 0;
}