/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104 */

#include <stdio.h>

int searchInsert(int nums[], int n, int target) {
    int left = 0, right = n - 1;

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

    return left;   // correct insert position
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    int position = searchInsert(nums, n, target);

    printf("Output: %d\n", position);

    return 0;
}