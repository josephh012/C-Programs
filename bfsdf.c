#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], n;

void initializeGraph() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

void bfs(int start) {
    int queue[MAX], front = -1, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS: ");
    while (front != rear) {
        front++;
        int current = queue[front];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
   
    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &start);

    // Reset visited array for BFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    bfs(start);

    // Reset visited array for DFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("DFS: ");
    dfs(start);
    printf("\n");

    return 0;
}