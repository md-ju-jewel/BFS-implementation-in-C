/// ** In the name of ALLAH ** ///

#include <stdio.h>
#include <stdlib.h>

#define N 5 // Number of nodes

// Predefined adjacency matrix
int a[N][N] =
{
    {0, 1, 0, 1, 0}, // Node 1
    {1, 0, 1, 1, 0}, // Node 2
    {0, 1, 0, 1, 1}, // Node 3
    {1, 1, 1, 0, 1}, // Node 4
    {0, 0, 1, 1, 0}  // Node 5
};

int visited[N] = {0}; // Visited array to mark visited nodes
int queue[N];         // Queue for BFS
int front = 0, rear = -1; // Queue pointers

void bfs(int start)
{
    int i;
    printf("BFS Traversal starting from node %d:\n", start + 1);

    // Enqueue the starting node and mark it as visited
    queue[++rear] = start;
    visited[start] = 1;

    // Process nodes in BFS manner
    while (front <= rear)
    {
        int current = queue[front++]; // Dequeue a node
        printf("%d ", current);   // Print the current node

        // Enqueue all adjacent, unvisited nodes
        for (i = 0; i < N; i++)
        {
            if (a[current][i] == 1 && visited[i]==0)
            {
                queue[++rear] = i; // Enqueue the node
                visited[i] = 1;    // Mark as visited
            }
        }
    }
    printf("\n");
}

int main()
{
    int start = 0; // Start BFS from node 0

    bfs(start); // Call BFS
    return 0;
}

