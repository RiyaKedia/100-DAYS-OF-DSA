/*  Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target. */

/*
Car Fleet Problem in C (VS Code Compatible)

Algorithm:
1. Store each car's position and speed.
2. Sort cars in descending order of position.
3. Compute time taken to reach target:
       time = (target - position) / speed
4. Traverse from nearest car to farthest:
   - If current car's time > last fleet time,
     it forms a new fleet.
   - Otherwise, it joins the existing fleet.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

// Comparator for sorting in descending order of position
int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {

    Car cars[n];

    // Store car data
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {

        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet formed
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {

    int target, n;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    int result = carFleet(target, position, speed, n);

    printf("Number of Car Fleets = %d\n", result);

    return 0;
}