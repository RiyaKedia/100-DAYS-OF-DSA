/* For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT). */

/*
Count Smaller Elements on Right Side
-----------------------------------

Approach: Merge Sort Technique

Idea:
- While merging two sorted halves,
  if right element < left element,
  then it is a smaller element appearing on right side.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {

    int n = right - left + 1;
    Pair temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int smallerRightCount = 0;

    while (i <= mid && j <= right) {

        if (arr[j].value < arr[i].value) {

            // Right element is smaller
            smallerRightCount++;
            temp[k++] = arr[j++];

        } else {

            // Add count to original index
            count[arr[i].index] += smallerRightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += smallerRightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

void mergeSort(Pair arr[], int left, int right, int count[]) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    printf("\n");

    return 0;
}