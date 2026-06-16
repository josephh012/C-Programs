#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adjMatrix[MAX][MAX], visited[MAX], queue[MAX], front = -1, rear = -1;

void DFS(int vertex, int numVertices) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);
    
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
        }
    }
}

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) { 
        front = 0;
    }
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return queue[front++];
}    

void BFS(int startVertex, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    
    enqueue(startVertex);
    visited[startVertex] = 1;
    
    while (front <= rear && front != -1) {
        int currentVertex = dequeue();
        if (currentVertex == -1) continue;
        
        printf("Visited %d\n", currentVertex);
       
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void initializeMatrix(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void readMatrix(int numVertices) {
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

int main() {
    int numVertices, choice = 1, startVertex;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    initializeMatrix(numVertices);
    readMatrix(numVertices);
    
    while (choice != 3) {
        printf("\nMenu\n1. DFS\n2. BFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                for (int i = 0; i < numVertices; i++) visited[i] = 0;
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("DFS starting from vertex %d:\n", startVertex);
                DFS(startVertex, numVertices);
                break;
            case 2:
                for (int i = 0; i < numVertices; i++) visited[i] = 0;
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                printf("BFS starting from vertex %d:\n", startVertex);
                BFS(startVertex, numVertices);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
