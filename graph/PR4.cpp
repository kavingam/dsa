#include <iostream>
#include <vector>

using namespace std;

// Node structure to represent a vertex in the adjacency list
struct Node {
  int vertex;
  Node* next;
};

// Graph class to manage the adjacency list
class Graph {
 private:
  int numVertices;
  vector<Node*> adjList;

 public:
  Graph(int numVertices) : numVertices(numVertices) {
    adjList.resize(numVertices, nullptr); // Initialize adjacency list with empty lists
  }

  void addEdge(int u, int v) {
    // Create new nodes for both vertices
    Node* newNodeU = new Node{u, nullptr};
    Node* newNodeV = new Node{v, nullptr};

    // Add edge from u to v
    newNodeU->next = adjList[u];
    adjList[u] = newNodeU;

    // Add edge from v to u for undirected graphs (symmetrical connection)
    newNodeV->next = adjList[v];
    adjList[v] = newNodeV;
  }

  void printGraph() {
    for (int v = 0; v < numVertices; ++v) {
      cout << "Adjacency list of vertex " << v << endl;
      Node* current = adjList[v];
      while (current) {
        cout << current->vertex << " ";
        current = current->next;
      }
      cout << endl;
    }
  }
};

int main() {
  int numVertices, numEdges;

  cout << "Enter the number of vertices in the graph: ";
  cin >> numVertices;

  cout << "Enter the number of edges: ";
  cin >> numEdges;

  Graph g(numVertices);

  // Get edges input from user
  int v1, v2;
  cout << "Enter edges (source vertex destination vertex):\n";
  for (int i = 0; i < numEdges; i++) {
    cin >> v1 >> v2;
    g.addEdge(v1, v2);
  }

  // Print the adjacency list representation
  cout << "Graph Representation:\n";
  g.printGraph();

  return 0;
}
