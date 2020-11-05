#include<stdio.h> 
#include<limits.h>
#define N 10
#define INF INT_MAX 

int min(int x, int y){
    return x < y? x: y;
}

int shortestDist(int graph[N][N]) { 
	int dist[N]; 

	dist[N-1] = 0; 

	// bottom up approach, so we start looping from the back, from the previous node to the destination
	for (int i = N - 2 ; i >= 0 ; i--) { 
		dist[i] = INF; 
		for (int j = i ; j < N ; j++) { 
			if (graph[i][j] == INF) 
				continue; 
			dist[i] = min(dist[i], graph[i][j] + dist[j]); 
		} 
	} 

	return dist[0]; 
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

	printf("%d\n", shortestDist(graph)); 
	return 0; 
} 
