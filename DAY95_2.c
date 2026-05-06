/* Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;

    // Step 1: Find min and max
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal) return 0;  // All elements same

    // Step 2: Calculate bucket size (gap)
    int gap = (maxVal - minVal + numsSize - 2) / (numsSize - 1);
    int bucketCount = numsSize - 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Step 3: Place elements into buckets
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == minVal || nums[i] == maxVal) continue;

        int idx = (nums[i] - minVal) / gap;
        if (idx >= bucketCount) idx = bucketCount - 1; // safety

        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    // Step 4: Find maximum gap
    int maxGap = 0;
    int prev = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) continue;

        int currentGap = bucketMin[i] - prev;
        if (currentGap > maxGap) maxGap = currentGap;

        prev = bucketMax[i];
    }

    // Final gap with maxVal
    if (maxVal - prev > maxGap) {
        maxGap = maxVal - prev;
    }

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}