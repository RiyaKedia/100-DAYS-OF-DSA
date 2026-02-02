/* Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. 
Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated */

#include <stdio.h>

int main() {
    int n, pos, x;

    // Read number of elements
    scanf("%d", &n);

    int arr[100];   // assuming max size 100

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position (1-based)
    scanf("%d", &pos);

    // Read element to insert
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}