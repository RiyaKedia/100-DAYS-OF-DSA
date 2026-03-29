/* Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4] */

#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to get Right Side View
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    if (root == NULL) return NULL;
    
    int* result = (int*)malloc(100 * sizeof(int));
    
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        int levelSize = rear - front;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            
            if (i == levelSize - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }
            
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }
    
    return result;
}

// Main function (TESTING)
int main() {
    /*
        Example Tree:
            1
           / \
          2   3
           \   \
            5   4
    */
    
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    
    int size;
    int* result = rightSideView(root, &size);
    
    printf("Right Side View: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    
    free(result);
    return 0;
}