 /*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node Definition
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

// DFS logic
int dfs(struct TreeNode* root, int* cameras) {
    if (root == NULL)
        return 2; // covered

    int left = dfs(root->left, cameras);
    int right = dfs(root->right, cameras);

    if (left == 0 || right == 0) {
        (*cameras)++;
        return 1; // has camera
    }

    if (left == 1 || right == 1) {
        return 2; // covered
    }

    return 0; // not covered
}

// Main function
int minCameraCover(struct TreeNode* root) {
    int cameras = 0;

    if (dfs(root, &cameras) == 0) {
        cameras++;
    }

    return cameras;
}

// ------------------ TEST ------------------
int main() {
    /*
        Example Tree:
            0
           /
          0
         / \
        0   0
    */

    struct TreeNode* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(0);

    int result = minCameraCover(root);
    printf("Minimum Cameras Needed: %d\n", result);

    return 0;
}