/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
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

// Helper function to build tree
struct TreeNode* helper(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    // Find index in inorder
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == rootVal)
            break;
    }

    // Build right first
    root->right = helper(inorder, postorder, index + 1, inEnd, postIndex);
    root->left  = helper(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}

// Main function to build tree
struct TreeNode* buildTree(int* inorder, int size, int* postorder) {
    int postIndex = size - 1;
    return helper(inorder, postorder, 0, size - 1, &postIndex);
}

// Print tree in preorder (for checking)
void printPreorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

// MAIN FUNCTION (VS Code execution starts here)
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int size = 5;

    struct TreeNode* root = buildTree(inorder, size, postorder);

    printf("Preorder traversal of constructed tree:\n");
    printPreorder(root);

    return 0;
}