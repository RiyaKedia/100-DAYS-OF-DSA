/* Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104 */

/*
Count of Smaller Numbers After Self
-----------------------------------

Approach: Modified Merge Sort

While merging:
- If left element > right element,
  then right element is smaller and lies to the right.
- Count how many right-side elements move before left element.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int counts[]) {

    int n = right - left + 1;
    Pair temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (arr[j].value < arr[i].value) {

            // Smaller element found on right
            rightCount++;
            temp[k++] = arr[j++];

        } else {

            // Add smaller elements count
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
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

void mergeSort(Pair arr[], int left, int right, int counts[]) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, counts);
    mergeSort(arr, mid + 1, right, counts);

    merge(arr, left, mid, right, counts);
}

int main() {

    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    Pair arr[n];
    int counts[n];

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        counts[i] = 0;
    }

    mergeSort(arr, 0, n - 1, counts);

    printf("Counts array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", counts[i]);
    }

    printf("\n");

    return 0;
}