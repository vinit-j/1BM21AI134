#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;

class BinarySearch {
public:
    int search(int arr[], int size, int num) {
        int first = 0;
        int last = size - 1;
        
        while (first <= last) {
            int middle = first + (last - first) / 2;
            
            if (arr[middle] == num) {
                return middle;
            } else if (arr[middle] < num) {
                first = middle + 1;
            } else {
                last = middle - 1;
            }
        }
        
        return -1; 
    }
};


class Graph {
public:
    typedef adjacency_list<vecS, vecS, directedS> DirectedGraph;
    
    DirectedGraph g;
    
    void addEdge(int from, int to) {
        add_edge(from, to, g);
    }
};

int main() {
    BinarySearch binarySearch;
    int arr[10];
    int num;
    
    cout << "Enter 10 Elements (in ascending order): ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    
    cout << "\nEnter Element to be Searched: ";
    cin >> num;
    
    int result = binarySearch.search(arr, 10, num);
    
    if (result != -1) {
        cout << "\nThe number, " << num << " found at Position " << result + 1 << endl;
    } else {
        cout << "\nThe number, " << num << " is not found in the given Array" << endl;
    }

    
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    return 0;
}
