/* Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000 */

#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);

    if (!head) return newNode;

    struct ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Insertion Sort
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = head;
    struct ListNode* cur = head->next;

    while (cur) {
        if (prev->val <= cur->val) {
            prev = cur;
            cur = cur->next;
        } else {
            struct ListNode* temp = dummy;

            while (temp->next && cur->val > temp->next->val)
                temp = temp->next;

            prev->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;

            cur = prev->next;
        }
    }
    return dummy->next;
}

// Main
int main() {
    int n, x;
    struct ListNode* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("\nOriginal List:\n");
    printList(head);

    head = insertionSortList(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}