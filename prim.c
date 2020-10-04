#include <stdio.h>
#include <string.h>
#define INF 9999999
#define N 10

void prim(int G[][N], int V){
    int E = 0, src, dest;
    int selected[V]; 
    memset(selected, 0, sizeof(selected));
    selected[0] = 1;
    
    printf("Source - Dest : Cost\n");

    while (E < V - 1) {

        int min = INF;
        src = 0;
        dest = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  
                        if (G[i][j] < min) {
                            min = G[i][j];
                            src = i;
                            dest = j;
                        }
                    }
                }
            }
        }
        printf("  %d       %d   : %d\n", src, dest, G[src][dest]);
        selected[dest] = 1;
        E++;
    }
}

int main() {
    int V = 0;
    int G[N][N];
    printf("Enter number of vertices\n");
    scanf("%d", &V);
    
    printf("Enter the adjacency matrix\n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            scanf("%d", &G[i][j]);
        }
    }
    
    prim(G, V);
  return 0;
}
