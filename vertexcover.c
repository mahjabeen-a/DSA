#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int start;
    int end;
} edge;
 
int vertex_cover(const edge* edges, int numEdges, int order, int **cover);

int main(){
    int numEdges, order;
    printf("Enter the number of edges and vertices: ");
    scanf("%d %d", &numEdges, &order);
    edge* edges = malloc(numEdges * sizeof(edge));
    int pos = 0;
    printf("Enter start and end vertex of the edge, and enter -1 to stop inputs\n");
    int s, e, flag = 0;
    scanf("%d %d", &s, &e);
    while(!flag){
        edges[pos].start = s;
        edges[pos].end = e;
        pos++;
        scanf("%d", &s);
        if (s == -1) break;
        scanf("%d", &e);
    }
    int *cover;
    int c = vertex_cover(edges, numEdges, order, &cover);
    printf("Cover size is %u\n", c);
    printf("Vertices in cover:\n");
    for (int i = 0; i < order; i++) {
        if (cover[i]) {
            printf("%u ", i);
        }
    }
    printf("\n");
    free(edges);
    free(cover);
    return 0;
}

int vertex_cover(const edge* edges, int numEdges, int order, int **cover){
    int notcovered_size = numEdges;
    int cover_size = 0;
    int* covered = calloc(numEdges, sizeof(int));
    *cover = calloc(order, sizeof(int));
    while (notcovered_size > 0) {
        int e, v;
        for (e = 0; e < numEdges && covered[e] == 1; e++);
        v = edges[e].start;
        (*cover)[v] = 1;
        cover_size++;
        for (e = 0; e < numEdges; e++) {
            if (!covered[e] && (edges[e].start == v || edges[e].end == v)) {
                covered[e] = 1;
                notcovered_size--;
            }
        }
    }
    free(covered);
    return cover_size;
}
