/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle (Floyd’s Algorithm)
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast)
            return true;            // cycle detected
    }

    return false;                   // no cycle
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Creating linked list: 3 -> 2 -> 0 -> -4
    struct ListNode* head = createNode(3);
    struct ListNode* second = createNode(2);
    struct ListNode* third = createNode(0);
    struct ListNode* fourth = createNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // 🔁 Uncomment below line to create a cycle
    fourth->next = second;

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}