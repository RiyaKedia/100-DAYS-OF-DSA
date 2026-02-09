/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.*/

#include <stdio.h>

void reverseString(char s[], int n) {
    int left = 0, right = n - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char s[100];
    int n = 0;

    printf("Enter a string: ");
    scanf("%s", s);   // reads string without spaces

    // find length
    while (s[n] != '\0') {
        n++;
    }

    reverseString(s, n);

    printf("Reversed string: %s\n", s);

    return 0;
}
