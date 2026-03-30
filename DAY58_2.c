/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the 
inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1] */

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

    // Safety check
    if (mid < left || mid > right) {
        printf("Invalid input! Preorder & Inorder mismatch.\n");
        exit(1);
    }

    root->left = buildHelper(preorder, left, mid - 1, inorderMap);
    root->right = buildHelper(preorder, mid + 1, right, inorderMap);

    return root;
}

// Build tree function
struct TreeNode* buildTree(int* preorder, int n, int* inorder) {
    int* inorderMap = (int*)malloc(sizeof(int) * 6001);
    int check[6001] = {0};

    // Store inorder indices
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i] + 3000] = i;
        check[inorder[i] + 3000] = 1;
    }

    // Validate preorder elements
    for (int i = 0; i < n; i++) {
        if (!check[preorder[i] + 3000]) {
            printf("Error: %d not found in inorder\n", preorder[i]);
            exit(1);
        }
    }

    preorderIndex = 0;
    return buildHelper(preorder, 0, n - 1, inorderMap);
}

// Print inorder (verification)
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    struct TreeNode* root = buildTree(preorder, n, inorder);

    printf("Constructed Tree (Inorder): ");
    printInorder(root);

    return 0;
}