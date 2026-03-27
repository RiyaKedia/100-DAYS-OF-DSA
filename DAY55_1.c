/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[++front];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Print Right View
void rightView(struct Node* root) {
    if (!root) return;

    front = rear = -1;
    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            // Last node of level
            if (i == size - 1) {
                printf("%d ", temp->data);
            }

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}