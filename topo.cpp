#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> indegree;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    indegree[v]++;
}

vector<int> topologicalSort(int n) {
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    adj.resize(n);
    indegree.resize(n, 0);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    vector<int> sorted = topologicalSort(n);

    cout << "Topological order:" << endl;
    for (int node : sorted) {
        cout << node << " ";
    }

    return 0;
}
