#include<iostream>
#include<vector>
#include<queue>
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

    // BFS Traversal
    void BFS() {    // O(V + E)
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(!Q.empty()) {
            int u = Q.front();  // u -> v
            Q.pop();

            cout << u << " ";

            for(int v : l[u]) { // Immediate Neighbor
                if(!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
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

    g.BFS();    // 0 1 2 3 4 5 6

    return 0;
}