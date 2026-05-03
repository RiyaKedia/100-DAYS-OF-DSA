/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int quickSelect(int* nums, int low, int high, int k) {
    while (low <= high) {
        int pivotIndex = low + rand() % (high - low + 1);
        int pivot = nums[pivotIndex];

        int lt = low, i = low, gt = high;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums, lt++, i++);
            } else if (nums[i] > pivot) {
                swap(nums, i, gt--);
            } else {
                i++;
            }
        }

        if (k < lt) {
            high = lt - 1;
        } else if (k > gt) {
            low = gt + 1;
        } else {
            return nums[k];
        }
    }
    return -1;
}

int findKthLargest(int* nums, int n, int k) {
    return quickSelect(nums, 0, n - 1, n - k);
}

int main() {
    int n, k;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    // Input array
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input k
    printf("Enter k: ");
    scanf("%d", &k);

    srand(time(0)); // seed random

    int result = findKthLargest(nums, n, k);

    printf("Kth largest element: %d\n", result);

    free(nums);
    return 0;
}