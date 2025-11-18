#include <stdio.h>
int adj[10][10], visited[10], n;
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            DFS(i);
}
void BFS(int start) {
    int queue[10], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 1; i <= n; i++)
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
    }
}
int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    for (i = 1; i <= n; i++) visited[i] = 0;
    DFS(start);
    printf("\nBFS Traversal: ");
    for (i = 1; i <= n; i++) visited[i] = 0;
    BFS(start);
    return 0;
}

