#include<stdio.h> 
#define N 4 
#define INF 999999 // as this algo is O(n^3), INT_MAX not suitable

void printSolution(int dist[][N], int V); 

void floydWarshall (int graph[][N], int V) { 
	int dist[V][V], i, j, k; 
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
			
	for (k = 0; k < V; k++) { 
		for (i = 0; i < V; i++) { 
			for (j = 0; j < V; j++) { 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
	printSolution(dist, V); 
} 

void printSolution(int dist[][N], int V) { 
	printf ("Shortest distances between every pair of vertices \n"); 
	for (int i = 0; i < V; i++) { 
		for (int j = 0; j < V; j++) { 
			if (dist[i][j] == INF) 
				printf("%7s", "INF"); 
			else
				printf ("%7d", dist[i][j]); 
		} 
		printf("\n"); 
	} 
} 
 
int main() { 
	int graph[N][N];
	int n;
	printf("Enter size of the graph: ");
	scanf("%d", &n);
	printf("Enter the adjaceny matrix\n");
	printf("If no edge exists btwn the vertices, or for distance btwn same vertex, enter -1\n");
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
	        scanf("%d", &graph[i][j]);
	        if (graph[i][j] == -1){
	            graph[i][j] = INF;
	        }
	    }
	}

	floydWarshall(graph, n); 
	return 0; 
} 
