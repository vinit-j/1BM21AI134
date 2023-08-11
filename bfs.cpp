#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
	int V;
	vector<vector<int>> adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj.resize(V);
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}

	void BFS(int s)
	{
		vector<bool> visited(V, false);
		queue<int> q;
		visited[s] = true;
		q.push(s);

		while (!q.empty())
            {
			s = q.front();
			cout << s << " ";
			q.pop();

			for (int adjacent : adj[s])
                {
				if (!visited[adjacent])
				{
					visited[adjacent] = true;
					q.push(adjacent);
				}
			}
		}
	}
};

int main() {
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 5);
	g.addEdge(2, 4);
	g.addEdge(0, 5);
	g.addEdge(0, 6);
	g.addEdge(4, 6);

	cout << "BFS Traversal from vertex 0:\n";
	g.BFS(0);

	return 0;
}
