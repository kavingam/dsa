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

void addMatrices(int rows, int cols, int matrix1[][cols], int matrix2[][cols], int result[][cols]) {
  // Check if matrices have same dimensions
  if (rows != rows || cols != cols) {
    cout << "Error: Matrices must have the same dimensions for addition." << endl;
    return;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

int main() {
  int rows, cols;

  cout << "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of columns: ";
  cin >> cols;

  // Declare matrices
  int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

  // Input elements for matrix 1
  cout << "Enter elements for matrix 1:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix1[i][j];
    }
  }

  // Input elements for matrix 2
  cout << "Enter elements for matrix 2:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix2[i][j];
    }
  }

  // Print matrices
  cout << "Matrix 1:\n";
  printMatrix(rows, cols, matrix1);

  cout << "Matrix 2:\n";
  printMatrix(rows, cols, matrix2);

  // Add matrices
  addMatrices(rows, cols, matrix1, matrix2, result);

  // Print result
  cout << "Sum of matrices:\n";
  printMatrix(rows, cols, result);

  return 0;
}
