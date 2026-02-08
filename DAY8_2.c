/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
