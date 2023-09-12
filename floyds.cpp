#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;

class FloydWarshall {
public:
    FloydWarshall(int V) : V(V) {
        dist = new int*[V];
        for (int i = 0; i < V; i++) {
            dist[i] = new int[V];
            for (int j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    ~FloydWarshall() {
        for (int i = 0; i < V; i++) {
            delete[] dist[i];
        }
        delete[] dist;
    }

    void findShortestPaths() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    void displayShortestPaths() {
        cout << "Shortest distances between all pairs of vertices:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

private:
    int V;
    int** dist;
    int graph[4][4] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
};

int main() {
    int V = 4;

    FloydWarshall floydWarshall(V);
    floydWarshall.findShortestPaths();
    floydWarshall.displayShortestPaths();

    return 0;
}
