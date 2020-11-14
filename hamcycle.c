#include <stdio.h> 
#include <stdbool.h>
#include <malloc.h>
#define N 5 

bool isValid(int vertex, int graph[N][N], int path[], int pos, int V) { 
	if (graph[path[pos-1]][vertex] == 0) return false; 
		
	for (int i = 0; i < pos; i++) 
		if (path[i] == vertex) 
		    return false; 
	return true; 
} 

int hamCyclePath(int graph[N][N], int path[], int pos, int V) { 
	if (pos == V) { 
		if (graph[path[pos-1]][path[0]] == 1 ) return 1; 
		else return 0; 
	} 
	for (int v = 1; v < V; v++) { 
		if (isValid(v, graph, path, pos, V)) { 
			path[pos] = v; 
			if (hamCyclePath(graph, path, pos+1, V) == 1) 
				return 1; 
			path[pos] = -1; 
		} 
	} 
	return 0; 
} 

void displaySoln(int path[], int V) { 
	printf ("One possible Hamiltonian Cycle is: \n"); 
	for (int i = 0; i < V; i++) 
		printf(" %d ", path[i]); 
		
	printf(" %d \n", path[0]); 
}

void HamiltonianCycle(int graph[N][N], int V) { 
	int *path = malloc(V * sizeof(int)); 
	path[0] = 0; 
	for (int i = 1; i < V; i++) 
		path[i] = -1; 
	if ( hamCyclePath(graph, path, 1, V) == 0 ) { 
		printf("\nNo Hamiltonian cycle"); return;
	} 
	displaySoln(path, V); 
} 

int main() { 
    int graph[N][N], V;
	printf("Enter size of the graph: ");
	scanf("%d", &V);
	printf("Enter the adjaceny matrix\n");
	for (int i = 0; i < V; i++)
	    for (int j = 0; j < V; j++)
	        scanf("%d", &graph[i][j]);
	HamiltonianCycle(graph, V);
	return 0; 
} 
