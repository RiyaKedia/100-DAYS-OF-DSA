/* Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly 
extract the maximum element and place it at the end of the array. */

#include <stdio.h>

/* Function to heapify a subtree rooted at index i */
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Assume root is largest
    int left = 2*i + 1;    // Left child
    int right = 2*i + 2;   // Right child
    int temp;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

/* Heap Sort function */
void heapSort(int arr[], int n)
{
    int temp;

    // Step 1: Build Max Heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap
    for(int i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array (Ascending):\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}