/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    if (head == NULL) return head; // empty list

    // If head itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    // If key is found
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    return head;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, key;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int value;
    scanf("%d", &value);
    struct Node* head = createNode(value);
    struct Node* current = head;

    // Read remaining n-1 elements
    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        current->next = createNode(value);
        current = current->next;
    }

    // Read key to delete
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteFirstOccurrence(head, key);

    // Print updated list
    printList(head);

    // Free remaining nodes
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}