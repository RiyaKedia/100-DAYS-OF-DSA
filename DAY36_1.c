/* Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. 
Display remaining elements in correct order. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter number of rotations (m): ");
    scanf("%d", &m);

    int front = 0;

    // rotate queue m times
    front = (front + m) % n;

    printf("Queue after operations:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", queue[(front + i) % n]);
    }

    free(queue);
    return 0;
}