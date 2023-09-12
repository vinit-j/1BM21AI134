#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int weight;
    int u, v;

    Edge(int w, int uu, int vv) : weight(w), u(uu), v(vv) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class MSTKruskal {
public:
    MSTKruskal(int vertices, int edges) : V(vertices), E(edges) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(weight, u, v));
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());

        vector<pair<int, int>> result;

        vector<int> parent(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int edgeCount = 0;
        for (auto edge : edges) {
            int weight = edge.weight;
            int u = edge.u;
            int v = edge.v;

            int parentU = find(parent, u);
            int parentV = find(parent, v);

            if (parentU != parentV) {
                result.push_back({u, v});
                unionSets(parent, parentU, parentV);
                edgeCount++;

                if (edgeCount == V - 1) {
                    break; // Minimum spanning tree found
                }
            }
        }

        cout << "Edges in Minimum Spanning Tree:\n";
        for (auto edge : result) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }

private:
    int V;
    int E;
    vector<Edge> edges;

    int find(vector<int>& parent, int node) {
        if (parent[node] != node) {
            parent[node] = find(parent, parent[node]);
        }
        return parent[node];
    }

    void unionSets(vector<int>& parent, int u, int v) {
        int parentU = find(parent, u);
        int parentV = find(parent, v);
        parent[parentU] = parentV;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    MSTKruskal mst(V, E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        mst.addEdge(u, v, weight);
    }

    mst.kruskalMST();

    return 0;
}
