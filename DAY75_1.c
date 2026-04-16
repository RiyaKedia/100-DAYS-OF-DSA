/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hash map using array (for simplicity)
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2;  // -2 means not visited
    }

    int sum = 0, maxLen = 0;

    // Important: sum = 0 at index -1
    hash[MAX] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int index = sum + MAX;

        if (hash[index] != -2) {
            int length = i - hash[index];
            if (length > maxLen) {
                maxLen = length;
            }
        } else {
            hash[index] = i;
        }
    }

    printf("Length of longest zero sum subarray = %d\n", maxLen);

    return 0;
}