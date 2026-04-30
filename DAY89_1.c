/* Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible). */

#include <stdio.h>

// Check if allocation is possible
int isPossible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages
        if (pages[i] > maxPages)
            return 0;

        if (currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];

            if (students > m)
                return 0;
        } else {
            currentSum += pages[i];
        }
    }

    return 1;
}

// Main function to find minimum pages
int allocateBooks(int pages[], int n, int m) {
    int sum = 0, max = pages[0];

    for (int i = 0; i < n; i++) {
        sum += pages[i];
        if (pages[i] > max)
            max = pages[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(pages, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;  // increase
        }
    }

    return result;
}

int main() {
    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int pages[n];

    printf("Enter pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int ans = allocateBooks(pages, n, m);

    printf("Minimum maximum pages: %d\n", ans);

    return 0;
}