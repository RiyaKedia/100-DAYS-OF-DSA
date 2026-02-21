/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100 */
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
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

// Function to find middle node (returns second middle if even length)
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to print linked list from a given node
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to create linked list from an array
struct ListNode* createListFromArray(int arr[], int n) {
    if (n == 0) return NULL;
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example input
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    struct ListNode* head = createListFromArray(arr, n);

    // Find middle node
    struct ListNode* mid = middleNode(head);

    // Print middle node and following nodes
    printf("Middle node and following nodes: ");
    printList(mid);

    return 0;
}