#include <stdio.h>

#define MAX 10
int n;
int cost[MAX][MAX];
int visited[MAX];
int min_cost = 1000000;
int path[MAX], best_path[MAX];

// Function to find TSP using backtracking
void tsp(int current, int count, int cost_so_far, int start) {
    visited[current] = 1;
    path[count] = current;

    if (count == n - 1) { // all cities visited
        int total_cost = cost_so_far + cost[current][start];
        if (total_cost < min_cost) {
            min_cost = total_cost;
            for (int i = 0; i < n; i++)
                best_path[i] = path[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                tsp(i, count + 1, cost_so_far + cost[current][i], start);
            }
        }
    }

    visited[current] = 0; // backtrack
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix (distance between cities):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    tsp(0, 0, 0, 0); // start from city 0

    printf("Minimum cost: %d\n", min_cost);
    printf("Tour: ");
    for (i = 0; i < n; i++)
        printf("%d -> ", best_path[i]);
    printf("0\n"); // return to start

    return 0;
}
