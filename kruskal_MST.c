#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int source;
    int dest;
    int cost;
} Edge;

int compare_cost(const Edge* e1, const Edge* e2){
    return (e1->cost > e2->cost) - (e1->cost < e2->cost);
}

int findParent(int v, int* parent){
    if (parent[v] == v) return v;
}

void kruskal(Edge* input, int n, int E){
    qsort(input, E, sizeof(Edge), (int(*)(const void *, const void *)) compare_cost);
    for (int i = 0; i < E; i++){
        printf("%d ", input[i].cost);
    }
    printf("\n");
    
    Edge* output = (Edge *)malloc((n-1) * sizeof(Edge));
    int* parent = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    int count = 0, i = 0;
    while (count != n-1){
        Edge curr = input[i];
        
        int srcParent = findParent(curr.source, parent);
        int destParent = findParent(curr.dest, parent);
        
        if (srcParent != destParent){
            output[count] = curr;
            count++;
            parent[srcParent] = destParent;
        }
        
        i++;
    }
    int mincost = 0;
    printf("Start End Cost: \n");
    for (int i = 0; i < n-1; i++){
        if (output[i].source < output[i].dest) {
            printf("%d    %d   %d\n", output[i].source, output[i].dest, output[i].cost);
        }
        else {
            printf("%d    %d   %d\n", output[i].dest, output[i].source, output[i].cost);
        }
        mincost += output[i].cost;
    }
    printf("The minimum is cost is %d\n", mincost);
}

int main()
{
    int n, E;
    printf("Enter number of vertices and edges: \n");
    scanf("%d %d", &n, &E);
    Edge *input = (Edge *)malloc(E * sizeof(Edge));
    
    printf("Enter starting vertex, ending vertex and cost of the Edge: \n");
    for (int i = 0; i < E; i++){
        scanf("%d %d %d", &input[i].source, &input[i].dest, &input[i].cost);
    }

    kruskal(input, n, E);
    return 0;
}
