#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1; // New node height is 1
    }
};

// AVL Tree Class
class AVLTree {
private:
    Node* root;

    // Get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }

    // Insert a node and balance the tree
    Node* insertNode(Node* node, int key) {
        // 1. Normal BST insert
        if (node == nullptr) return new Node(key);
        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        else
            return node; // No duplicate keys allowed

        // 2. Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Check balance factor
        int balance = getBalance(node);

        // 4. Apply rotations if unbalanced

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        // Return unchanged node
        return node;
    }

    // Get the node with minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Delete a node and balance the tree
    Node* deleteNode(Node* root, int key) {
        // 1. Perform normal BST deletion
        if (root == nullptr) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                // No child case
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else // One child case
                    *root = *temp;

                delete temp;
            }
            else {
                // Node with two children
                Node* temp = minValueNode(root->right);

                root->key = temp->key;

                root->right = deleteNode(root->right, temp->key);
            }
        }

        // If the tree had only one node
        if (root == nullptr) return root;

        // 2. Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // 3. Check balance factor
        int balance = getBalance(root);

        // 4. Apply rotations if unbalanced

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Search a key in AVL Tree
    bool searchNode(Node* node, int key) {
        if (node == nullptr) return false;
        if (key == node->key) return true;
        else if (key < node->key) return searchNode(node->left, key);
        else return searchNode(node->right, key);
    }

    // Print tree in-order
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    // Insert public method
    void insert(int key) {
        root = insertNode(root, key);
    }

    // Delete public method
    void remove(int key) {
        root = deleteNode(root, key);
    }

    // Search public method
    bool search(int key) {
        return searchNode(root, key);
    }

    // Display the tree
    void display() {
        inOrder(root);
        cout << endl;
    }
};

// Main function to test AVL Tree
int main() {
    AVLTree tree;

    // Insert 15 nodes
    int values[15] = { 20, 4, 15, 70, 50, 100, 80, 10, 5, 3, 30, 25, 60, 90, 85 };
    for (int i = 0; i < 15; i++) {
        tree.insert(values[i]);
    }

    cout << "In-order traversal of AVL Tree: ";
    tree.display();

    // Search for a value
    int searchKey = 25;
    cout << "Searching for " << searchKey << ": "
        << (tree.search(searchKey) ? "Found" : "Not Found") << endl;

    // Insert a new value
    tree.insert(55);
    cout << "After inserting 55: ";
    tree.display();

    // Delete a value
    tree.remove(20);
    cout << "After deleting 20: ";
    tree.display();

    return 0;
}
