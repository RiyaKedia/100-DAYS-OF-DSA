/* Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10 */

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

/* Queue Operations */
void enqueue(int x) {
    rear++;
    queue[rear] = x;
}

int dequeue() {
    int x = queue[front];
    front++;
    return x;
}

/* Stack Operations */
void push(int x) {
    top++;
    stack[top] = x;
}

int pop() {
    int x = stack[top];
    top--;
    return x;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    /* Step 1: Move queue → stack */
    for(int i = front; i <= rear; i++) {
        push(dequeue());
    }

    /* Step 2: Move stack → queue */
    while(top != -1) {
        enqueue(pop());
    }

    /* Print reversed queue */
    printf("Reversed Queue:\n");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}