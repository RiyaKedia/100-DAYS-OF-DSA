/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 */

 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function to check mirror
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
        return true;

    if (t1 == NULL || t2 == NULL)
        return false;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// ✅ FIXED FUNCTION
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

// Driver Code
int main() {
    // Example 1: Symmetric tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("true\n");
    else
        printf("false\n");

    // Example 2: Not symmetric (change tree)
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);

    if (isSymmetric(root2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}