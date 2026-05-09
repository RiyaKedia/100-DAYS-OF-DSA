/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

// Comparator function for sorting
int compare(const void *a, const void *b)
{
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;

    return x->start - y->start;
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    // Input intervals
    printf("Enter intervals (start end):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort intervals according to start value
    qsort(arr, n, sizeof(Interval), compare);

    // Array to store merged intervals
    Interval merged[n];

    int index = 0;

    // Put first interval
    merged[0] = arr[0];

    // Traverse remaining intervals
    for (int i = 1; i < n; i++)
    {
        // Check overlap
        if (arr[i].start <= merged[index].end)
        {
            // Update end if needed
            if (arr[i].end > merged[index].end)
            {
                merged[index].end = arr[i].end;
            }
        }
        else
        {
            // No overlap -> move to next interval
            index++;
            merged[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("\nMerged Intervals:\n");

    for (int i = 0; i <= index; i++)
    {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }

    return 0;
}