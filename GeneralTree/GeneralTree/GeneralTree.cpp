#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ????? ?????? Node
class Node {
public:
    int data;
    vector<Node*> children; // ???? ???? ????? ???? ?? ???

    Node(int value) {
        data = value;
    }
};

// ????? ???? ???? General Tree
class GeneralTree {
private:
    Node* root;

    // ???? ??? ?????? (DFS)
    bool searchHelper(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;

        for (Node* child : node->children) {
            if (searchHelper(child, key)) return true;
        }
        return false;
    }

    // ???? ?????? ?????
    bool deleteHelper(Node* parent, Node* node, int key) {
        if (node == nullptr) return false;

        // ???? ??? ????? ?????? ???????
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if ((*it)->data == key) {
                // ??? ?????
                deleteSubTree(*it);
                node->children.erase(it);
                return true;
            }
            if (deleteHelper(node, *it, key)) return true;
        }
        return false;
    }

    // ??? ???? ????? ???????
    void deleteSubTree(Node* node) {
        for (Node* child : node->children) {
            deleteSubTree(child);
        }
        delete node;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    // ????? ?????? ?? 15 Node
    void createSampleTree() {
        root = new Node(1);
        queue<Node*> q;
        q.push(root);
        int value = 2;

        while (value <= 15) {
            Node* current = q.front();
            q.pop();

            // ?? ???? ????? ??? 2 ????? ???????
            for (int i = 0; i < 2 && value <= 15; i++) {
                Node* child = new Node(value++);
                current->children.push_back(child);
                q.push(child);
            }
        }
    }

    // ????? ?? ????
    bool search(int key) {
        return searchHelper(root, key);
    }

    // ????? ???? ????? ???? ???? Node ?????
    void insert(int parentValue, int newValue) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == parentValue) {
                Node* newNode = new Node(newValue);
                current->children.push_back(newNode);
                cout << "Inserted " << newValue << " under parent " << parentValue << endl;
                return;
            }

            for (Node* child : current->children) {
                q.push(child);
            }
        }
        cout << "Parent " << parentValue << " not found.\n";
    }

    // ??? ???? ?????
    void deleteValue(int key) {
        if (root == nullptr) return;

        if (root->data == key) {
            deleteSubTree(root);
            root = nullptr;
            cout << "Root deleted. Tree is empty now.\n";
            return;
        }

        if (deleteHelper(nullptr, root, key)) {
            cout << "Deleted node with value " << key << endl;
        }
        else {
            cout << "Value " << key << " not found.\n";
        }
    }

    // ??? ?????? (BFS)
    void display() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << ": ";
            for (Node* child : current->children) {
                cout << child->data << " ";
                q.push(child);
            }
            cout << endl;
        }
    }
};

// ???? main ???????
int main() {
    GeneralTree tree;
    tree.createSampleTree();

    cout << "Initial Tree:\n";
    tree.display();

    // ?????
    cout << "\nSearch for 10: " << (tree.search(10) ? "Found" : "Not Found") << endl;

    // ???????
    tree.insert(5, 20);

    // ?????
    tree.deleteValue(3);

    cout << "\nTree after operations:\n";
    tree.display();

    return 0;
}
