/*You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(KthLargest *obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (obj->heap[parent] <= obj->heap[index])
            break;
        swap(&obj->heap[parent], &obj->heap[index]);
        index = parent;
    }
}

void heapifyDown(KthLargest *obj, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&obj->heap[index], &obj->heap[smallest]);
        index = smallest;
    }
}

void push(KthLargest *obj, int val) {
    obj->heap[obj->size] = val;
    obj->size++;
    heapifyUp(obj, obj->size - 1);
}

void pop(KthLargest *obj) {
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;
    heapifyDown(obj, 0);
}

KthLargest* createKthLargest(int k, int nums[], int numsSize) {
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * (k + 1));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        push(obj, nums[i]);
        if (obj->size > k)
            pop(obj);
    }

    return obj;
}

int add(KthLargest *obj, int val) {
    push(obj, val);
    if (obj->size > obj->k)
        pop(obj);
    return obj->heap[0];
}

int main() {

    int nums[] = {4, 5, 8, 2};
    int size = 4;
    int k = 3;

    KthLargest *kthLargest = createKthLargest(k, nums, size);

    printf("%d\n", add(kthLargest, 3));  
    printf("%d\n", add(kthLargest, 5));  
    printf("%d\n", add(kthLargest, 10)); 
    printf("%d\n", add(kthLargest, 9));  
    printf("%d\n", add(kthLargest, 4));  

    return 0;
}