/*Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.
*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// Check if we can place k cows with minimum distance >= dist
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // first cow in first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];

            if (count == k)
                return 1; // success
        }
    }
    return 0; // not possible
}

// Main logic
int maxMinDistance(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), cmp);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;      // possible → try bigger
            low = mid + 1;
        } else {
            high = mid - 1; // not possible → reduce
        }
    }

    return ans;
}

int main() {
    int n, k;

    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter stall positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    int result = maxMinDistance(stalls, n, k);

    printf("Maximum minimum distance = %d\n", result);

    return 0;
}