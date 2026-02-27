/* Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer
 points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle 
 starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, 
 it will print false. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    return node;
}

bool detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

void removeLoop(struct Node* head) {
    if (!head || !head->next) return;

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = NULL;
            return;
        }
    }
}

int main() {
    int n, pos;
    scanf("%d", &n);

    if (n <= 0) {
        printf("false");
        return 0;
    }

    int x;
    scanf("%d", &x);
    struct Node* head = newNode(x);
    struct Node* tail = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        tail->next = newNode(x);
        tail = tail->next;
    }

    scanf("%d", &pos);

    if (pos != -1) {
        struct Node* loopNode = head;
        for (int i = 0; i < pos; i++)
            loopNode = loopNode->next;
        tail->next = loopNode;
    }

    bool hadLoop = detectLoop(head);
    removeLoop(head);

    if (hadLoop)
        printf("true");
    else
        printf("false");

    return 0;
}