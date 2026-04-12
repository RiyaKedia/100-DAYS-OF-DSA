/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1

// Insert using quadratic probing
void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash Table Overflow\n");
}

// Search using quadratic probing
int search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == EMPTY)
            return 0;

        i++;
    }

    return 0;
}

int main() {
    int m, q;

    // Input size of hash table
    scanf("%d", &m);

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    // Number of operations
    scanf("%d", &q);

    char operation[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}