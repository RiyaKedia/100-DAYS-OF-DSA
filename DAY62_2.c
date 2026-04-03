/* There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room. */

#include <stdio.h>
#include <stdbool.h>

// DFS function
void dfs(int roomsSize, int* roomsColSize, int rooms[1000][1000], int room, bool visited[]) {
    if (visited[room]) return;

    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        dfs(roomsSize, roomsColSize, rooms, key, visited);
    }
}

// Main logic
bool canVisitAllRooms(int roomsSize, int* roomsColSize, int rooms[1000][1000]) {
    bool visited[1000] = {false};

    dfs(roomsSize, roomsColSize, rooms, 0, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    int n;

    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int rooms[1000][1000];
    int roomsColSize[1000];

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomsColSize[i]);

        printf("Enter keys: ");
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    // Function call
    if (canVisitAllRooms(n, roomsColSize, rooms)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}