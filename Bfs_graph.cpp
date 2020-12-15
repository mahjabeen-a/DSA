#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void breadthFirstSearch(vector<vector<int>> adjMatrix, int source, int v, int e){
    vector<bool> visited(v);
    queue<int> graphQueue;
    graphQueue.push(source);
    
    while(!graphQueue.empty()){
        int src = graphQueue.front();
        if (!visited[src]){
            cout << src << " ";
            visited[src] = true;
        }
        graphQueue.pop();
        for (int i = 0; i < v; i++){
            if (adjMatrix[src][i] && !visited[i]){
                graphQueue.push(i);
            }
        }
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
    breadthFirstSearch(adjMatrix, source, v, e);
    
    return 0;
}
