#include<iostream>
#include<vector>
using namespace std;

// Undirected unweighted graph
class Graph {
    int V;
    vector<vector<int>> l;

public:
    Graph(int V) : V(V), l(V) {}

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // DFS Traversal
    void dfsHelper(int u, vector<bool>& vis) {  // O(V + E)
        cout << u << " ";
        vis[u] = true;

        for(int v : l[u]) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        int src = 0;
        vector<bool> vis(V, false);

        // If the graph is disconnected
        // It has multiple connected components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfsHelper(src, vis);
            }
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.dfs();    // 0 1 2 5 3 4 6

    return 0;
}