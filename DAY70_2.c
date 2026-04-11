/*                                                                                              There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

2 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
 
*/

#include <stdio.h>
#include <limits.h>

int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    
    int dist[n];

    // Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax edges k+1 times
    for(int i = 0; i <= k; i++) {
        int temp[n];

        // Copy current distances
        for(int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        // Relax all flights
        for(int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int cost = flights[j][2];

            if(dist[u] != INT_MAX && dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }

        // Update dist array
        for(int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main() {
    int n, m;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of flights: ");
    scanf("%d", &m);

    int flights[m][3];

    printf("Enter flights (from to price):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
    }

    int src, dst, k;

    printf("Enter source, destination and k: ");
    scanf("%d %d %d", &src, &dst, &k);

    int result = findCheapestPrice(n, flights, m, src, dst, k);

    if(result == -1)
        printf("No valid route found\n");
    else
        printf("Cheapest price: %d\n", result);

    return 0;
}