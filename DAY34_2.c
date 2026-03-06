/* Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char *s) {
    long num = 0;
    int stack[300000];
    int top = -1;
    char sign = '+';

    int n = strlen(s);

    for (int i = 0; i <= n; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || c == '\0') {

            if (sign == '+')
                stack[++top] = num;

            else if (sign == '-')
                stack[++top] = -num;

            else if (sign == '*')
                stack[top] = stack[top] * num;

            else if (sign == '/')
                stack[top] = stack[top] / num;

            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++)
        result += stack[i];

    return result;
}

int main() {
    char s[300000];

    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);

    int result = calculate(s);

    printf("Result: %d\n", result);

    return 0;
}