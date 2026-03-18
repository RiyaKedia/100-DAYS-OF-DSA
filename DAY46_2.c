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

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            printf("%d ", node->val);

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}