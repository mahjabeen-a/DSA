#include <iostream>
#include <vector>

using namespace std;

void depthFirstSearch(vector<vector<int>> adjMatrix, int source, int v, int e){
    static vector<bool> visited(v);
    visited[source] = true;
    cout << source << " ";
    for (int i = 0; i < v; i++){
        if (adjMatrix[source][i] && !visited[i])
            depthFirstSearch(adjMatrix, i, v, e);
    }
}

int main(){
    int v, e;
    cout << "Enter num of vertices and edges\n";
    cin >> v >> e;
    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    cout << "Enter edges (undirected graph)\n";
    
    int src, dest;
    for (int i = 0; i < e; i++){
        cin >> src >> dest;
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
    
    int source;
    cout << "Enter source vertex to start BFS\n";
    cin >> source;
    depthFirstSearch(adjMatrix, source, v, e);
    
    return 0;
}
