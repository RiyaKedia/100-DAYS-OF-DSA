/* Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j]. */

#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int left, int mid, int right) {
    int n = right - left + 1;

    int *temp = (int *)malloc(n * sizeof(int));

    int i = left;
    int j = mid + 1;
    int k = 0;

    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // Count inversions
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < n; i++) {
        arr[left + i] = temp[i];
    }

    free(temp);

    return invCount;
}

int mergeSort(int arr[], int left, int right) {
    int invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, left, mid);

        invCount += mergeSort(arr, mid + 1, right);

        invCount += merge(arr, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversions = mergeSort(arr, 0, n - 1);

    printf("Number of Inversions = %d\n", inversions);

    free(arr);

    return 0;
}