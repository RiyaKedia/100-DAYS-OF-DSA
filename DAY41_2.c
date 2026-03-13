/*You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
 
*/

#include <stdio.h>

int leastInterval(char tasks[], int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequency
    for(int i = 0; i < tasksSize; i++){
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count tasks with max frequency
    int countMax = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] == maxFreq)
            countMax++;
    }

    int intervals = (maxFreq - 1) * (n + 1) + countMax;

    if(tasksSize > intervals)
        return tasksSize;
    else
        return intervals;
}

int main() {
    int n, size;

    printf("Enter number of tasks: ");
    scanf("%d", &size);

    char tasks[size];

    printf("Enter tasks (A-Z): ");
    for(int i = 0; i < size; i++){
        scanf(" %c", &tasks[i]);
    }

    printf("Enter cooling interval n: ");
    scanf("%d", &n);

    int result = leastInterval(tasks, size, n);

    printf("Minimum CPU intervals required: %d\n", result);

    return 0;
}