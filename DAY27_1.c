/* Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Find intersection based on first common value
int findIntersection(struct Node* head1, struct Node* head2) {
    for (struct Node* p1 = head1; p1 != NULL; p1 = p1->next) {
        for (struct Node* p2 = head2; p2 != NULL; p2 = p2->next) {
            if (p1->data == p2->data) {
                return p1->data;  // first common value
            }
        }
    }
    return -1;
}

int main() {
    int n, m, x;

    // First list
    scanf("%d", &n);
    struct Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* temp = createNode(x);
        if (head1 == NULL) {
            head1 = tail1 = temp;
        } else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    // Second list
    scanf("%d", &m);
    struct Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* temp = createNode(x);
        if (head2 == NULL) {
            head2 = tail2 = temp;
        } else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}