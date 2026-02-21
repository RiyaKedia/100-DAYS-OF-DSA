/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50 */
#include <stdio.h>
#include <stdlib.h>

// Definition for singly linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from user input
struct ListNode* createList(int n) {
    if (n <= 0) return NULL;

    int val;
    scanf("%d", &val);
    struct ListNode* head = createNode(val);
    struct ListNode* current = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        current->next = createNode(val);
        current = current->next;
    }
    return head;
}

// Function to traverse and print linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);  // Read number of nodes

    struct ListNode* head = createList(n);  // Create linked list from input

    printList(head);  // Print all elements

    return 0;
}