/* Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front, rear, size, capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* dq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    dq->arr = (int*)malloc(sizeof(int) * k);
    dq->capacity = k;
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

bool myCircularDequeIsFull(MyCircularDeque* dq) {
    return dq->size == dq->capacity;
}

bool myCircularDequeIsEmpty(MyCircularDeque* dq) {
    return dq->size == 0;
}

bool myCircularDequeInsertFront(MyCircularDeque* dq, int value) {
    if (myCircularDequeIsFull(dq))
        return false;

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = value;
    dq->size++;

    if (dq->size == 1)
        dq->rear = dq->front;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* dq, int value) {
    if (myCircularDequeIsFull(dq))
        return false;

    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = value;
    dq->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* dq) {
    if (myCircularDequeIsEmpty(dq))
        return false;

    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* dq) {
    if (myCircularDequeIsEmpty(dq))
        return false;

    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* dq) {
    if (myCircularDequeIsEmpty(dq))
        return -1;
    return dq->arr[dq->front];
}

int myCircularDequeGetRear(MyCircularDeque* dq) {
    if (myCircularDequeIsEmpty(dq))
        return -1;
    return dq->arr[dq->rear];
}

void myCircularDequeFree(MyCircularDeque* dq) {
    free(dq->arr);
    free(dq);
}

int main() {
    int k, choice, value;

    printf("Enter size of deque: ");
    scanf("%d", &k);

    MyCircularDeque* dq = myCircularDequeCreate(k);

    while (1) {
        printf("\n1.Insert Front\n2.Insert Last\n3.Delete Front\n4.Delete Last\n5.Get Front\n6.Get Rear\n7.Is Empty\n8.Is Full\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("%s\n", myCircularDequeInsertFront(dq,value) ? "true":"false");
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("%s\n", myCircularDequeInsertLast(dq,value) ? "true":"false");
            break;

        case 3:
            printf("%s\n", myCircularDequeDeleteFront(dq) ? "true":"false");
            break;

        case 4:
            printf("%s\n", myCircularDequeDeleteLast(dq) ? "true":"false");
            break;

        case 5:
            printf("%d\n", myCircularDequeGetFront(dq));
            break;

        case 6:
            printf("%d\n", myCircularDequeGetRear(dq));
            break;

        case 7:
            printf("%s\n", myCircularDequeIsEmpty(dq) ? "true":"false");
            break;

        case 8:
            printf("%s\n", myCircularDequeIsFull(dq) ? "true":"false");
            break;

        case 9:
            myCircularDequeFree(dq);
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}