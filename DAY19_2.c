/* Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n. */

#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = nums[0];
    int curr_max = nums[0], max_sum = nums[0];
    int curr_min = nums[0], min_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        curr_max = max(nums[i], curr_max + nums[i]);
        max_sum = max(max_sum, curr_max);

        curr_min = min(nums[i], curr_min + nums[i]);
        min_sum = min(min_sum, curr_min);

        total += nums[i];
    }

    // If all elements are negative
    if (max_sum < 0)
        return max_sum;

    return max(max_sum, total - min_sum);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);
    printf("Maximum Circular Subarray Sum = %d\n", result);

    return 0;
}