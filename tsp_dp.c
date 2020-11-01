#include <stdio.h>
#include <math.h>
#define N 5
#define INT_MAX 999999
int all_visited;

int min(int x, int y){
    return x < y? x: y;
}

int  tsp(int mask, int vertex, int distance[N][N], int dptable[N][N], int n){
	if(mask == all_visited) return distance[vertex][0];
	if(dptable[mask][vertex] != -1) return dptable[mask][vertex];
	int ans = INT_MAX;
	for(int v = 0; v < n; v++){
		if((mask & (1 << v)) == 0){
			int newAns = distance[vertex][v] + tsp(mask | (1 << v), v, distance, dptable, n);
			ans = min(ans, newAns);
		}
	}
	return dptable[mask][vertex] = ans;
} 
 
int main(){
    int n, cost = 0, up = pow(2,N), distance[N][N], dptable[up][N];
    printf("Enter size of adjacency matrix: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) scanf("%d", &distance[i][j]);
    }
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0;j < n; j++) dptable[i][j] = -1;
    }
    all_visited = (1 << n) -1;
	cost = tsp(1, 0, distance, dptable, n); 
	printf("\nMinimum cost is %d\n ",cost);
	return 0;
}
