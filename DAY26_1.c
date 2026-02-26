/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to display list forward
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, value;
    Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    displayForward(head);

    return 0;
}