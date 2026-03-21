#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct Node {
    int puzzle[N][N];
    int x, y; // empty tile position
    int cost; // heuristic cost
    struct Node *parent;
} Node;

// Goal state
int goal[N][N] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

// Heuristic: number of misplaced tiles
int misplaced(int puzzle[N][N]) {
    int count = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(puzzle[i][j] && puzzle[i][j] != goal[i][j])
                count++;
    return count;
}

// Print puzzle
void printPuzzle(int puzzle[N][N]) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d ", puzzle[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if two puzzles are equal
int isEqual(int a[N][N], int b[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(a[i][j] != b[i][j])
                return 0;
    return 1;
}

// Create new node
Node* createNode(int puzzle[N][N], int x, int y, Node* parent) {
    Node *node = (Node*)malloc(sizeof(Node));
    memcpy(node->puzzle, puzzle, sizeof(node->puzzle));
    node->x = x;
    node->y = y;
    node->parent = parent;
    node->cost = misplaced(puzzle);
    return node;
}

// Priority Queue (simple array-based for demo)
Node* queue[1000];
int front = 0, rear = 0;

void enqueue(Node *node) {
    queue[rear++] = node;
}

Node* dequeue() {
    int min = queue[front]->cost;
    int idx = front;
    for(int i=front;i<rear;i++){
        if(queue[i]->cost < min){
            min = queue[i]->cost;
            idx = i;
        }
    }
    Node *node = queue[idx];
    for(int i=idx;i<rear-1;i++)
        queue[i] = queue[i+1];
    rear--;
    return node;
}

// Directions: up, down, left, right
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// Solve puzzle using Best-First Search
void solve(int start[N][N]) {
    int x, y;
    // Find empty tile
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(start[i][j]==0){ x=i; y=j; break; }

    Node *root = createNode(start, x, y, NULL);
    enqueue(root);

    while(front < rear) {
        Node *current = dequeue();

        if(isEqual(current->puzzle, goal)){
            printf("Solution found:\n");
            Node *path = current;
            while(path){
                printPuzzle(path->puzzle);
                path = path->parent;
            }
            return;
        }

        // Generate moves
        for(int i=0;i<4;i++){
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if(newX>=0 && newX<N && newY>=0 && newY<N){
                int tempPuzzle[N][N];
                memcpy(tempPuzzle, current->puzzle, sizeof(tempPuzzle));
                // Swap empty tile
                int temp = tempPuzzle[newX][newY];
                tempPuzzle[newX][newY] = tempPuzzle[current->x][current->y];
                tempPuzzle[current->x][current->y] = temp;
                Node *child = createNode(tempPuzzle, newX, newY, current);
                enqueue(child);
            }
        }
    }

    printf("No solution found.\n");
}

int main() {
    int start[N][N];

    printf("Enter initial 8-puzzle configuration (0 for empty space):\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d", &start[i][j]);

    solve(start);

    return 0;
}
