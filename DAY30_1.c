/* Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* temp = createNode(c, e);

    if (head == NULL)
        return temp;

    struct Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}

// Print polynomial in standard form
void printPolynomial(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->exp == 0)
            printf("%d", curr->coeff);
        else if (curr->exp == 1)
            printf("%dx", curr->coeff);
        else
            printf("%dx^%d", curr->coeff, curr->exp);

        if (curr->next != NULL)
            printf(" + ");

        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    // Input number of terms
    scanf("%d", &n);

    // Input coefficient and exponent
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    // Output polynomial
    printPolynomial(head);

    return 0;
}