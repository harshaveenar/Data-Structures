#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int n; 
int e[MAX_VERTICES][MAX_VERTICES]; 
int q[MAX_VERTICES], front = 0, rear = -1; 
int visited[MAX_VERTICES];

void bfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    q[++rear] = v;
    while (front <= rear) {
        v = q[front++];
        for (i = 0; i < n; i++) {
            if (e[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                q[++rear] = i;
            }
        }
    }
}

int main() {
    int i, j, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &e[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);
    return 0;
}

