#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minDist(int *dist, bool *setNode){
    int index, minimum = INT_MAX, i;
    for(i = 0; i < V; i++){
        if(setNode[i] == false && dist[i] <= minimum){
            minimum = dist[i];
            index = i;
        }
    }
    return index;
}

void display(int *dist, int start){
    int i;
    for(i = 0; i < V; i++){
        printf("Shortest distance of %d from %d is %d\n", i, start, dist[i]);
    }
}

void dijkstra(int graph[V][V], int start){

    int dist[V], i, j;
    bool setNode[V];

    for(i = 0; i < V; i++){
        dist[i] = INT_MAX;
        setNode[i] = false;
    }
    
    dist[start] = 0;

    for(i = 0; i < V; i++){
        int u = minDist(dist, setNode);
        setNode[u] = true;
        for(j = 0; j < V; j++){
            if(setNode[j] == false && graph[u][j] && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
        }
    }

    display(dist, start);
}

int main(){
    int graph[V][V];
    int n;
    printf("Enter the adjacency matrix of the graph with %d vertices\n", V);
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra(graph, 0);                  
}
