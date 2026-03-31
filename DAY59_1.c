/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Build tree helper
struct TreeNode* buildHelper(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    // Find root index in inorder
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == rootVal)
            break;
    }

    // Build right first
    root->right = buildHelper(inorder, postorder, index + 1, inEnd, postIndex);
    root->left  = buildHelper(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}

// Build tree
struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildHelper(inorder, postorder, 0, n - 1, &postIndex);
}

// Preorder traversal (Output)
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// MAIN FUNCTION
int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    // Input inorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    // Input postorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    struct TreeNode* root = buildTree(inorder, postorder, n);

    // Output preorder
    preorder(root);

    return 0;
}