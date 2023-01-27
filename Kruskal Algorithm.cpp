#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n,adj[MAX][MAX],state[MAX],from[MAX],min,cost=0;

void create_graph(){
    int i,max_edges,origin,destin;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edges=n*(n-1)/2;
    for(i=1;i<=max_edges;i++){
        printf("Enter edge %d( -1 -1 to quit ) : ",i);
        scanf("%d %d",&origin,&destin);
        if((origin==-1) && (destin==-1))
            break;
        if(origin>=n || destin>=n || origin<0 || destin<0){
            printf("Invalid edge!\n");
            i--;
        }
        else{
            printf("Enter the weight for this edge : ");
            scanf("%d",&adj[origin][destin]);
            adj[destin][origin]=adj[origin][destin];
        }
    }
}

int get_next_state(int k){
    int i,min=999;
    for(i=0;i<n;i++){
        if(adj[k][i]!=0 && state[i]!=visited){
            if(adj[k][i]<min){
                min=adj[k][i];
                from[i]=k;
            }
        }
    }
    return min;
}

void kruskals(){
    int i,j,k,u;
    for(i=0;i<n;i++){
        state[i]=initial;
        from[i]=-1;
    }
    printf("Minimum Spanning Tree : \n");
    for(i=0;i<n;i++){
        k=0;
        min=999;
        for(j=0;j<n;j++){
            if(state[j]!=visited && from[j]!=-1){
                u=get_next_state(j);
                if(u<min){
                    min=u;
                    k=j;
                }
            }
        }
        printf("%d to %d : %d\n",from[k],k,min);
        cost+=min;
        state[k]=visited;
    }
    printf("Minimum Cost : %d\n",cost);
}

int main(){
    create_graph();
    kruskals();
    return 0;
}

