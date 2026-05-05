/* Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output. */

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // Step 1: Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    // Step 3: Store frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build output array (stable, traverse from end)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free memory
    free(count);
    free(output);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}