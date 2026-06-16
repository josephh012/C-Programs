#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Graph represented as an adjacency matrix
int graph[MAX][MAX];
bool visited[MAX];
int queue[MAX], front = -1, rear = -1;

// BFS traversal
void bfs(int start, int n) {
    int i;
    front = 0;
    rear = 0;
    queue[rear] = start;
    visited[start] = true;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void dfs(int start, int n) {
    printf("%d ", start);
    visited[start] = true;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, e, u, v, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    printf("Enter edges (u v) format:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Since this is an undirected graph
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    // BFS Traversal
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    bfs(start, n);

    // DFS Traversal
    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    dfs(start, n);
    printf("\n");

    return 0;
}
