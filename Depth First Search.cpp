#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int n; 
int adj[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES]; 

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

  
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

 
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Depth First Search: ");
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            DFS(i);
        }
    }

    return 0;
}

