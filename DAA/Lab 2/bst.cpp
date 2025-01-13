#include <iostream>
using namespace std;

// Define the structure for a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;  // Replacing nullptr with NULL
        right = NULL; // Replacing nullptr with NULL
    }
};

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Recursive function to search for a value in the BST
bool search(Node* root, int value, int &steps) {
    steps++; // Increment the step count
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value, steps);
    } else {
        return search(root->right, value, steps);
    }
}

// Function to display the BST in-order (for verification purposes)
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int n, value, steps;

    // Create the BST
    cout << "Enter the number of elements to insert into the BST: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order Traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    // Search in the BST
    cout << "Enter the value to search: ";
    cin >> value;

    steps = 0;
    if (search(root, value, steps)) {
        cout << "Value " << value << " found in the BST in " << steps << " steps." << endl;
    } else {
        cout << "Value " << value << " not found in the BST. Steps taken: " << steps << endl;
    }

    return 0;
}

