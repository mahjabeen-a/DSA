#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

class Graph{
public:
    int num_vertices, num_edges;
    vector<pair<int, int>> edges;
    
    Graph(int V, int E){
        num_vertices = V;
        num_edges = E;
        edges.resize(E);
    }
};
// naive logic, O(n)

int find(int parent[], int i){
    if (parent[i] == -1){
        return i; //the vertex is parent of itself
    }
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y){
    parent[x] = y;
}

bool isCycle(Graph graph){
    int V = graph.num_vertices;
    int* parent = new int[V];
    memset(parent, -1, V * sizeof(int));
    
    for (int i = 0; i < graph.num_edges; i++){
        int p1 = find(parent, graph.edges[i].first);
        int p2 = find(parent, graph.edges[i].second);
        if (p1 == p2){
            return true;
        }
        Union(parent, p1, p2);
    }
    return false;
}

int main(){
    int v, e;
    cout << "Enter num of vertices and edges\n";
    cin >> v >> e;
    
    Graph g(v, e);
  
    cout << "Enter the edges\n";
    for (int i = 0; i < e; i++){
        cin >> g.edges[i].first >> g.edges[i].second;
    }
    
    if (isCycle(g))
       cout << "There is a cycle\n"; 
    else
        cout <<"No cycle\n";
    return 0;
}
