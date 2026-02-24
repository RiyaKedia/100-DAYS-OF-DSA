/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head. 

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50*/
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to remove elements with value 'val'
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node to handle removal of head easily
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print linked list
void printList(struct ListNode* head) {
    printf("[");
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        temp = temp->next;
        if (temp != NULL) printf(", ");
    }
    printf("]\n");
}

int main() {
    // Example: head = [1,2,6,3,4,5,6], val = 6
    int values[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(values)/sizeof(values[0]);
    int valToRemove = 6;

    // Create linked list
    struct ListNode* head = createNode(values[0]);
    struct ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }

    printf("Original list: ");
    printList(head);

    // Remove elements
    head = removeElements(head, valToRemove);

    printf("After removal of %d: ", valToRemove);
    printList(head);

    // Free remaining nodes
    current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}