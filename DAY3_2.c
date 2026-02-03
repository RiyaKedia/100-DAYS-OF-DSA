/* Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1
*/
#include <stdio.h>

/* Examples:
Input: arr[] = {1, 2, 3, 5}
Output: 4
*/

int missingNum(int arr[], int size) {
    int n = size + 1;
    long long totalSum = (long long)n * (n + 1) / 2;
    long long arrSum = 0;

    for (int i = 0; i < size; i++) {
        arrSum += arr[i];
    }

    return (int)(totalSum - arrSum);
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Missing number: %d\n", missingNum(arr, size));

    return 0;
}