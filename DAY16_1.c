/* Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count */

#include <stdio.h>

int main() {
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for (int i = 0; i < n; i++) {
        int count = 1;

        // Skip if already counted
        if (arr[i] == -1)
            continue;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1; // mark as counted
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}