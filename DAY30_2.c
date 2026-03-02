/* ou are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and 
each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Stack implementation
typedef struct {
    int arr[200];
    int top;
} Stack;

void push(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to add two numbers represented as linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    // Push digits into stacks
    while (l1) {
        push(&s1, l1->val);
        l1 = l1->next;
    }
    while (l2) {
        push(&s2, l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* head = NULL;

    while (!isEmpty(&s1) || !isEmpty(&s2) || carry) {
        int sum = carry;

        if (!isEmpty(&s1)) sum += pop(&s1);
        if (!isEmpty(&s2)) sum += pop(&s2);

        carry = sum / 10;

        struct ListNode* node = newNode(sum % 10);
        node->next = head;
        head = node;
    }

    return head;
}

// Function to create linked list from array
struct ListNode* createList(int n) {
    struct ListNode *head = NULL, *tail = NULL;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct ListNode* temp = newNode(x);
        if (!head) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// Function to print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;

    // Input first list
    scanf("%d", &n);
    struct ListNode* l1 = createList(n);

    // Input second list
    scanf("%d", &m);
    struct ListNode* l2 = createList(m);

    struct ListNode* result = addTwoNumbers(l1, l2);

    // Output result list
    printList(result);

    return 0;
}