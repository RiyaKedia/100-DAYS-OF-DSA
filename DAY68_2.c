/* A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.
Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters. */

#include <stdio.h>
#include <string.h>

#define MAX 26
#define MAX_WORDS 500
#define MAX_LEN 100

int q[MAX], front = 0, rear = 0;

void enqueue(int x) { q[rear++] = x; }
int dequeue() { return q[front++]; }
int isEmpty() { return front == rear; }

// Function to check if order is valid
int isValid(char words[][MAX_LEN], int n, char order[]) {
    int pos[26];

    // Store position of each character in order
    for (int i = 0; order[i]; i++) {
        pos[order[i] - 'a'] = i;
    }

    // Check lexicographic order
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int j = 0;
        while (w1[j] && w2[j] && w1[j] == w2[j]) j++;

        if (w1[j] && w2[j]) {
            if (pos[w1[j] - 'a'] > pos[w2[j] - 'a'])
                return 0;
        } else if (w1[j] && !w2[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    char words[MAX_WORDS][MAX_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int found = 0;

        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!graph[u][v]) {
                    graph[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        if (!found && len1 > len2) {
            printf("false\n");
            return 0;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(i);
        }
    }

    char result[MAX];
    int index = 0;

    while (!isEmpty()) {
        int u = dequeue();
        result[index++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) count++;
    }

    if (index != count) {
        printf("false\n");
        return 0;
    }

    result[index] = '\0';

    // Validate order
    if (isValid(words, n, result))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}