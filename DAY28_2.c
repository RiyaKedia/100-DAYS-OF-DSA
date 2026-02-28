/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    slow = reverse(slow);

    struct ListNode* first = head;
    struct ListNode* second = slow;

    // Compare halves
    while (second != NULL) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }

    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        if (head == NULL) {
            head = createNode(value);
            temp = head;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    if (isPalindrome(head))
        printf("Output: true\n");
    else
        printf("Output: false\n");

    return 0;
}