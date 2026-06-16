#include <stdio.h>

#define MAX 100  // Maximum number of vertices

// Global variables
int graph[MAX][MAX];     // Adjacency matrix
int visited[MAX];        // Visited array for tracking visited vertices
int stack[MAX];          // Stack for DFS
int queue[MAX];          // Queue for BFS

// DFS using an array-based stack
void DFS(int numVertices, int startVertex) {
    int top = -1;                 // Initialize stack as empty
    stack[++top] = startVertex;    // Push start vertex onto the stack
    visited[startVertex] = 1;      // Mark start vertex as visited

    printf("DFS Traversal: ");
    while (top >= 0) {             // Continue until stack is empty
        int vertex = stack[top--]; // Pop vertex from stack
        printf("%d ", vertex);     // Process the vertex

        // Push all unvisited adjacent vertices to the stack
        for (int i = numVertices - 1; i >= 0; i--) {  // Reverse order for consistent DFS
            if (graph[vertex][i] == 1 && !visited[i]) {
                stack[++top] = i;  // Push vertex onto stack
                visited[i] = 1;    // Mark vertex as visited
            }
        }
    }
    printf("\n");
}

// BFS using an array-based queue
void BFS(int numVertices, int startVertex) {
    int front = 0, rear = -1;      // Initialize queue as empty
    queue[++rear] = startVertex;   // Enqueue start vertex
    visited[startVertex] = 1;      // Mark start vertex as visited

    printf("BFS Traversal: ");
    while (front <= rear) {        // Continue until queue is empty
        int vertex = queue[front++]; // Dequeue vertex from queue
        printf("%d ", vertex);     // Process the vertex

        // Enqueue all unvisited adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                queue[++rear] = i; // Enqueue vertex
                visited[i] = 1;    // Mark vertex as visited
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int numVertices, numEdges;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    // User input for graph
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter edges (format: src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;  // Comment this line if the graph is directed
    }

    int startVertex;
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    // Perform DFS
    for (int i = 0; i < numVertices; i++) visited[i] = 0;  // Reset visited array
    DFS(numVertices, startVertex);

    // Perform BFS
    for (int i = 0; i < numVertices; i++) visited[i] = 0;  // Reset visited array
    BFS(numVertices, startVertex);

    return 0;
}
