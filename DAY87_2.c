/* Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109 */

#include <stdio.h>

// Function to calculate total hours needed
long long calculateHours(int piles[], int n, int k) {
    long long hours = 0;
    for(int i = 0; i < n; i++) {
        hours += (piles[i] + k - 1) / k; // ceil(piles[i] / k)
    }
    return hours;
}

// Function to find minimum eating speed
int minEatingSpeed(int piles[], int n, int h) {
    int low = 1, high = piles[0];

    // Find max pile
    for(int i = 1; i < n; i++) {
        if(piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        long long hours = calculateHours(piles, n, mid);

        if(hours <= h) {
            ans = mid;
            high = mid - 1; // try smaller speed
        } else {
            low = mid + 1; // increase speed
        }
    }

    return ans;
}

int main() {
    int n, h;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    printf("Enter elements of piles:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }

    printf("Enter hours (h): ");
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);

    printf("Minimum eating speed (k): %d\n", result);

    return 0;
}