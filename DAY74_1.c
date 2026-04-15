/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    
    // Input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[MAX][LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output
    printf("%s %d\n", winner, maxVotes);

    return 0;
}