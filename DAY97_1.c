/* Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

/* ---------- Min Heap Functions ---------- */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);
}

int top(int heap[]) {
    return heap[0];
}

/* ---------- Sort Meetings by Start Time ---------- */

int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

/* ---------- Main Logic ---------- */

int minMeetingRooms(Meeting meetings[], int n) {

    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    int maxRooms = 0;

    for (int i = 0; i < n; i++) {

        // Free room if meeting ended
        if (heapSize > 0 && meetings[i].start >= top(heap)) {
            pop(heap, &heapSize);
        }

        // Allocate room
        push(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    return maxRooms;
}

int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting meetings[n];

    printf("Enter start and end times:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    int result = minMeetingRooms(meetings, n);

    printf("Minimum rooms required = %d\n", result);

    return 0;
}