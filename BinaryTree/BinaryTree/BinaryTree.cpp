#include <iostream>
using namespace std;

// Node structure for the Binary Tree
struct Node {
    int data;         // Value stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child

    Node(int value) { // Constructor to initialize a node
        data = value;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;       // Root node of the tree

    // Helper function to insert a value into the tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); // Create new node if empty spot found
        }
        if (value < node->data) {
            node->left = insert(node->left, value); // Go left if value is smaller
        }
        else {
            node->right = insert(node->right, value); // Go right if value is greater
        }
        return node;
    }

    // Helper function to search for a value in the tree
    bool search(Node* node, int value) {
        if (node == nullptr) return false;  // Base case: value not found
        if (node->data == value) return true; // Value found
        if (value < node->data)
            return search(node->left, value); // Search left subtree
        else
            return search(node->right, value); // Search right subtree
    }

    // Helper function to find the smallest value in a subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left; // Keep going left
        }
        return node;
    }

    // Helper function to delete a value from the tree
    Node* remove(Node* node, int value) {
        if (node == nullptr) return node; // Value not found

        if (value < node->data) {
            node->left = remove(node->left, value); // Go left
        }
        else if (value > node->data) {
            node->right = remove(node->right, value); // Go right
        }
        else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp; // Return right child
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp; // Return left child
            }

            // Node with two children
            Node* temp = findMin(node->right); // Find smallest in right subtree
            node->data = temp->data; // Replace value
            node->right = remove(node->right, temp->data); // Delete duplicate
        }
        return node;
    }

    // Helper function to print the tree in-order
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);           // Visit left child
            cout << node->data << " ";     // Print current node
            inorder(node->right);          // Visit right child
        }
    }

public:
    BinaryTree() { root = nullptr; } // Constructor: start with empty tree

    // Public function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to search for a value
    bool search(int value) {
        return search(root, value);
    }

    // Public function to remove a value
    void remove(int value) {
        root = remove(root, value);
    }

    // Public function to print the tree
    void display() {
        inorder(root);
        cout << endl;
    }
};

// Main function
int main() {
    BinaryTree tree;

    // Insert 15 nodes
    int values[15] = { 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85 };
    for (int v : values) {
        tree.insert(v);
    }

    cout << "Binary Tree In-order Traversal: ";
    tree.display();

    // Search for a number
    int searchVal = 25;
    cout << "Searching for " << searchVal << ": "
        << (tree.search(searchVal) ? "Found" : "Not Found") << endl;

    // Add a number
    tree.insert(90);
    cout << "After inserting 90: ";
    tree.display();

    // Delete a number
    tree.remove(30);
    cout << "After removing 30: ";
    tree.display();

    return 0;
}
