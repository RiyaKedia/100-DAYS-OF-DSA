/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104*/

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
    printf("Enter intervals:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort intervals based on start time
    qsort(arr, n, sizeof(Interval), compare);

    // Array to store merged intervals
    Interval result[n];

    int index = 0;

    // First interval
    result[0] = arr[0];

    // Merge intervals
    for (int i = 1; i < n; i++)
    {
        // Overlapping interval
        if (arr[i].start <= result[index].end)
        {
            // Update end if needed
            if (arr[i].end > result[index].end)
            {
                result[index].end = arr[i].end;
            }
        }
        else
        {
            // Non-overlapping interval
            index++;
            result[index] = arr[i];
        }
    }

    // Output merged intervals
    printf("\nMerged Intervals:\n");

    for (int i = 0; i <= index; i++)
    {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }

    return 0;
}