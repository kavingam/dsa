#include <iostream>
#include <vector>

/* There are two main ways to represent graphs in C++:

Adjacency Matrix: This approach uses a 2D array where rows and columns represent vertices. A non-zero value at a specific position (i, j) indicates an edge between vertex i and vertex j. This is efficient for checking if an edge exists but can be wasteful for sparse graphs (graphs with few edges) since it allocates space for all possible edges.

Adjacency List: This approach uses an array of lists. Each element in the array represents a vertex and the corresponding list stores its neighboring vertices. This is more space-efficient for sparse graphs but requires iterating through the list for adjacency checks.

Here's an example program for an undirected graph using adjacency list representation:*/

using namespace std;

class Graph {
 private:
  int numVertices;
  vector<list<int>> adjList;

 public:
  Graph(int numVertices) : numVertices(numVertices) {
    adjList.resize(numVertices);
  }

  void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graphs
  }

  void printGraph() {
    for (int v = 0; v < numVertices; ++v) {
      cout << "Adjacency list of vertex " << v << endl;
      for (auto itr = adjList[v].begin(); itr != adjList[v].end(); ++itr) {
        cout << *itr << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  int numVertices = 5;
  Graph g(numVertices);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  cout << "Graph Representation\n";
  g.printGraph();

  return 0;
}
