#include <stdio.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX];
int front = 0, rear = 0;
int n; // number of vertices

// Enqueue function
void enqueue(int v) {
    queue[rear++] = v;
}

// Dequeue function
int dequeue() {
    return queue[front++];
}

// BFS function
void BFS(int start) {
    int i, current;
    visited[start] = 1;
    enqueue(start);

    while (front < rear) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int edges, u, v, i, j;

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

    printf("BFS traversal starting from vertex 0:\n");
    BFS(0);

    return 0;
}
