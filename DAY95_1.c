/* Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate. */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // Create buckets
    float** buckets = (float**)malloc(n * sizeof(float*));
    int* bucketSizes = (int*)calloc(n, sizeof(int));

    // Initialize each bucket with size 0
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        if (idx >= n) idx = n - 1;  // Safety check

        bucketSizes[idx]++;
        buckets[idx] = (float*)realloc(buckets[idx], bucketSizes[idx] * sizeof(float));
        buckets[idx][bucketSizes[idx] - 1] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}