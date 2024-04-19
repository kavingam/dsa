#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
};

// Function to create a new node
Node* newNode(int data) {
  Node* temp = new Node;
  temp->data = data;
  temp->left = temp->right = nullptr;
  return temp;
}

// In-order traversal function
void inOrderTraversal(Node* root) {
  if (root != nullptr) {
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
  }
}

// Function to insert a node into the binary search tree
Node* insert(Node* root, int data) {
  if (root == nullptr) {
    return newNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}

int main() {
  
