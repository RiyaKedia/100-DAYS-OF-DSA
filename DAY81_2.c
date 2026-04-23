/* Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order. */

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } 
        else if (nums[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    // Input array (sorted)
    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input target
    printf("Enter target: ");
    scanf("%d", &target);

    int result = search(nums, n, target);

    if(result != -1)
        printf("Target found at index: %d\n", result);
    else
        printf("Target not found (-1)\n");

    return 0;
}
