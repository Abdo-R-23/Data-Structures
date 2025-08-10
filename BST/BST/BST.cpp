#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); // Create new node if current is null
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value); // Go to left subtree
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value); // Go to right subtree
        }
        return node; // Return the unchanged node pointer
    }

    // Helper function to search for a value
    bool searchNode(Node* node, int value) {
        if (node == nullptr) return false; // Value not found
        if (node->data == value) return true; // Value found
        if (value < node->data)
            return searchNode(node->left, value); // Search in left subtree
        else
            return searchNode(node->right, value); // Search in right subtree
    }

    // Helper function to find minimum value in a subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = deleteNode(node->left, value); // Go to left subtree
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value); // Go to right subtree
        }
        else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: get inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Helper function for inorder traversal
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Public function to insert value
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Public function to search value
    bool search(int value) {
        return searchNode(root, value);
    }

    // Public function to delete value
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Public function to display tree
    void display() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert 15 nodes
    int values[15] = { 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85 };
    for (int i = 0; i < 15; i++) {
        tree.insert(values[i]);
    }

    cout << "BST Inorder Traversal: ";
    tree.display();

    // Search for a value
    int searchValue = 45;
    cout << "Searching for " << searchValue << ": ";
    if (tree.search(searchValue))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Delete a value
    int deleteValue = 30;
    cout << "Deleting " << deleteValue << endl;
    tree.remove(deleteValue);

    cout << "BST after deletion: ";
    tree.display();

    return 0;
}
