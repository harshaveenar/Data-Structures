#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 99999

int n;
int graph[MAX][MAX];
int parent[MAX];
int key[MAX];
bool visited[MAX];

void prim() {
    int i, j, u, v, min;

    for(i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(i = 1; i < n; i++) {
        min = INF;
        for(j = 1; j <= n; j++) {
            if(visited[j] == false && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = true;

        for(v = 1; v <= n; v++) {
            if(graph[u][v] && visited[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim();

    printf("Edge \tWeight\n");
    for(i = 2; i <= n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }

    return 0;
}

