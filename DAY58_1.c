/* Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees. */

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int preorderIndex = 0;

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree helper
struct TreeNode* buildHelper(int* preorder, int left, int right, int* inorderMap) {
    if (left > right) return NULL;

    int rootVal = preorder[preorderIndex++];
    struct TreeNode* root = createNode(rootVal);

    int mid = inorderMap[rootVal + 3000];

    root->left = buildHelper(preorder, left, mid - 1, inorderMap);
    root->right = buildHelper(preorder, mid + 1, right, inorderMap);

    return root;
}

// Build tree
struct TreeNode* buildTree(int* preorder, int n, int* inorder) {
    int* inorderMap = (int*)malloc(sizeof(int) * 6001);

    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i] + 3000] = i;
    }

    preorderIndex = 0;
    return buildHelper(preorder, 0, n - 1, inorderMap);
}

// 🔥 Postorder traversal (LEFT → RIGHT → ROOT)
void printPostorder(struct TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

// Main
int main() {
    int n;

    scanf("%d", &n);

    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    struct TreeNode* root = buildTree(preorder, n, inorder);

    printPostorder(root);

    return 0;
}