#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";
        for (int adjacent : adj[v]) {
            if (!visited[adjacent]) {
                DFS(adjacent);
            }
        }
    }
};

int main() {
    Graph g;
   g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 5);
	g.addEdge(2, 4);
	g.addEdge(0, 5);
	g.addEdge(0, 6);
	g.addEdge(4, 6);

	g.addEdge(1, 0);
	g.addEdge(2, 0);
	g.addEdge(3, 1);
	g.addEdge(5, 3);
	g.addEdge(4, 2);
	g.addEdge(5, 0);
	g.addEdge(6, 0);
	g.addEdge(6, 4);

    cout << "DFS Traversal from vertex 2: ";
    g.DFS(5);

    return 0;
}

