/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int topIndex;
} MinStack;

void initMinStack(MinStack* obj) {
    obj->topIndex = -1;
}

void push(MinStack* obj, int val) {
    obj->topIndex++;
    obj->stack[obj->topIndex] = val;

    if (obj->topIndex == 0)
        obj->minStack[obj->topIndex] = val;
    else {
        int currentMin = obj->minStack[obj->topIndex - 1];
        obj->minStack[obj->topIndex] = (val < currentMin) ? val : currentMin;
    }
}

void pop(MinStack* obj) {
    obj->topIndex--;
}

int top(MinStack* obj) {
    return obj->stack[obj->topIndex];
}

int getMin(MinStack* obj) {
    return obj->minStack[obj->topIndex];
}

int main() {
    MinStack ms;
    initMinStack(&ms);

    int n;
    scanf("%d", &n);

    char operation[20];
    int value;

    printf("[");

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "MinStack") == 0) {
            printf("null");
        }
        else if (strcmp(operation, "push") == 0) {
            scanf("%d", &value);
            push(&ms, value);
            printf("null");
        }
        else if (strcmp(operation, "pop") == 0) {
            pop(&ms);
            printf("null");
        }
        else if (strcmp(operation, "top") == 0) {
            printf("%d", top(&ms));
        }
        else if (strcmp(operation, "getMin") == 0) {
            printf("%d", getMin(&ms));
        }

        if (i != n - 1)
            printf(",");
    }

    printf("]");
    return 0;
}