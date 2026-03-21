#include <stdio.h>
#define MAX 100

int n; // number of nodes
int graph[MAX][MAX];
int heuristic[MAX]; // heuristic values
int visited[MAX];

// Find the unvisited node with minimum heuristic
int minHeuristicNode() {
    int min = 100000; // large number
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && heuristic[i] < min) {
            min = heuristic[i];
            index = i;
        }
    }
    return index;
}

void bestFirstSearch(int start, int goal) {
    int current = start;
    visited[current] = 1;

    printf("Path: %d ", current);

    while (current != goal) {
        int next = -1;
        int min_h = 100000;

        // Choose unvisited neighbor with minimum heuristic
        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i] && heuristic[i] < min_h) {
                min_h = heuristic[i];
                next = i;
            }
        }

        if (next == -1) {
            printf("\nNo path found.\n");
            return;
        }

        visited[next] = 1;
        current = next;
        printf("-> %d ", current);
    }

    printf("\nReached goal node %d.\n", goal);
}

int main() {
    int edges, u, v, start, goal;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) pairs (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    printf("Enter heuristic values for each node:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &heuristic[i]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter start node and goal node: ");
    scanf("%d %d", &start, &goal);

    bestFirstSearch(start, goal);

    return 0;
}
