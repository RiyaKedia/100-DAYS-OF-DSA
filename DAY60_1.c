/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order array
struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct TreeNode* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Count total nodes
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isCBT(struct TreeNode* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isCBT(root->left, 2*index + 1, totalNodes) &&
           isCBT(root->right, 2*index + 2, totalNodes);
}

// Check Min Heap Property (FIXED)
int isMinHeap(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    if (root->left && root->val > root->left->val)
        return 0;

    if (root->right && root->val > root->right->val)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n, 0);

    int totalNodes = countNodes(root);

    if (isCBT(root, 0, totalNodes) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}