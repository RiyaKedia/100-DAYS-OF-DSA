/*                                                                                                                    Problem: Implement Insertion Sort - Implement the algorithm.
Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/
#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // element to be placed correctly
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;  // place key at correct position
    }
}

int main() {
    int n;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    insertionSort(arr, n);

    // Output sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

