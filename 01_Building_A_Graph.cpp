#include<iostream>
#include<vector>
using namespace std;

// Undirected unweighted graph
class Graph {
    int V;
    vector<vector<int>> l;

public:
    Graph(int V) : V(V), l(V) {
        // l is initialized with V empty vectors via the member initializer list
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList() {
        for(int i = 0; i < V; i++) {
            cout << i << " : ";
            for(int neighbor : l[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();

    return 0;
}