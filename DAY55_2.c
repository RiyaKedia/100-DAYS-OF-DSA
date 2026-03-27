/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue
struct Queue {
    struct TreeNode* data[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[++q->rear] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[++q->front];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Function
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue q;
    q.front = q.rear = -1;

    enqueue(&q, root);

    int* result = (int*)malloc(100 * sizeof(int));
    int size = 0;

    while (!isEmpty(&q)) {
        int levelSize = q.rear - q.front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(&q);

            if (i == levelSize - 1) {
                result[size++] = node->val;
            }

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
    }

    *returnSize = size;
    return result;
}

// MAIN FUNCTION (THIS WAS MISSING)
int main() {
    // Example: [1,2,3,null,5,null,4]

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    int size;
    int* result = rightSideView(root, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}