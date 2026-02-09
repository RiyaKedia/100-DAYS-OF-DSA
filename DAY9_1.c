/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/

#include <stdio.h>

int main() {
    char s[1000];
    int i, length = 0;

    // Input
    scanf("%s", s);   // reads a lowercase string without spaces

    // Find length of string
    while (s[length] != '\0') {
        length++;
    }

    // Reverse (mirror) the string
    for (i = length - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    return 0;
}
