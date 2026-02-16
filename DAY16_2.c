/* Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. */

#include <stdio.h>

void rotate(int nums[], int n, int k) {
    k = k % n;  // Handle k greater than n

    int temp[n];

    // Copy last k elements to temp
    for (int i = 0; i < k; i++) {
        temp[i] = nums[n - k + i];
    }

    // Copy remaining elements
    for (int i = k; i < n; i++) {
        temp[i] = nums[i - k];
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int n, k;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    // Input array elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Input k
    printf("Enter k (number of rotations): ");
    scanf("%d", &k);

    // Rotate array
    rotate(nums, n, k);

    // Print rotated array
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}