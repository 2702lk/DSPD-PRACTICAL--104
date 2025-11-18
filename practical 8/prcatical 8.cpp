#include <stdio.h>
#define INF 999
void dijkstra(int n, int cost[10][10], int start) {
    int dist[10], visited[10], i, j, min, next;
    for (i = 1; i <= n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 1; j <= n; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                next = j;
            }
        visited[next] = 1;
        for (j = 1; j <= n; j++)
            if (!visited[j] && dist[next] + cost[next][j] < dist[j])
                dist[j] = dist[next] + cost[next][j];
    }
    printf("Shortest distances:\n");
    for (i = 1; i <= n; i++)
        printf("%d -> %d = %d\n", start, i, dist[i]);
}
int main() {
    int n, cost[10][10], i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &start);
    dijkstra(n, cost, start);
    return 0;
}

