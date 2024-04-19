#include <iostream>

using namespace std;

void printMatrix(int rows, int cols, int matrix[][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int numVertices;

  cout << "Enter the number of vertices in the graph: ";
  cin >> numVertices;

  // Adjacency matrix to represent the graph
  int adjMatrix[numVertices][numVertices];

  // Initialize all elements to 0 (no edges initially)
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  // Get edges input from user
  int v1, v2;
  cout << "Enter edges (source vertex destination vertex). Enter -1 -1 to stop.\n";
  while (true) {
    cin >> v1 >> v2;
    if (v1 == -1 && v2 == -1) {
      break;
    }

    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
      adjMatrix[v1][v2] = 1;
      adjMatrix[v2][v1] = 1; // For undirected graphs
    } else {
      cout << "Invalid vertex entered. Please enter vertices within range (0 to " << numVertices - 1 << ").\n";
    }
  }

  // Print the adjacency matrix
  cout << "Adjacency Matrix:\n";
  printMatrix(numVertices, numVertices, adjMatrix);

  return 0;
}
