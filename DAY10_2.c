/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;

    // Input size of first array
    printf("Enter size of nums1: ");
    scanf("%d", &n1);

    int nums1[n1];
    printf("Enter elements of nums1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input size of second array
    printf("Enter size of nums2: ");
    scanf("%d", &n2);

    int nums2[n2];
    printf("Enter elements of nums2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    int freq[1001] = {0};
    int result[1000];
    int k = 0;

    // Count frequency of nums1
    for (int i = 0; i < n1; i++) {
        freq[nums1[i]]++;
    }

    // Find intersection
    for (int i = 0; i < n2; i++) {
        if (freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    // Output result
    printf("Intersection: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
