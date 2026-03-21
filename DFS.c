#include <stdio.h>

#define MAX 100

int visited[MAX];
int graph[MAX][MAX];
int n; // number of vertices

// DFS function
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) pairs (0-based index):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // for undirected graph
    }

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}
