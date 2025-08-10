#include <iostream>
#include <string>
using namespace std;

// Maximum number of words allowed in the Trie
const int MAX_WORDS = 15;

// Node structure for Trie
class TrieNode {
public:
    TrieNode* children[26]; // Pointers to child nodes for each letter
    bool isEndOfWord;       // True if the node represents end of a word

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;
    int wordCount; // Number of words currently in the Trie

    // Helper function for deleting a word
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // If we reached end of the word
        if (depth == word.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return isEmpty(node); // Delete node if it has no children
        }

        int index = word[depth] - 'a';
        if (deleteHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isEndOfWord && isEmpty(node);
        }
        return false;
    }

    // Check if a node has no children
    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) return false;
        }
        return true;
    }

    // Helper function for displaying all words
    void displayHelper(TrieNode* node, string current) {
        if (node->isEndOfWord) {
            cout << current << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                displayHelper(node->children[i], current + char(i + 'a'));
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
        wordCount = 0;
    }

    // Insert a new word into the Trie
    void insert(const string& word) {
        if (wordCount >= MAX_WORDS) {
            cout << "Cannot insert more than " << MAX_WORDS << " words.\n";
            return;
        }
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        if (!node->isEndOfWord) {
            node->isEndOfWord = true;
            wordCount++;
        }
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Delete a word from the Trie
    void remove(const string& word) {
        if (deleteHelper(root, word, 0)) {
            wordCount--;
            cout << "Word deleted successfully.\n";
        }
        else {
            cout << "Word not found.\n";
        }
    }

    // Display all words in the Trie
    void display() {
        cout << "Words in Trie:\n";
        displayHelper(root, "");
    }
};

// Main function to test the Trie
int main() {
    Trie trie;

    // Insert some words
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("apple");
    trie.insert("bat");

    // Display all words
    trie.display();

    // Search for a word
    string searchWord = "car";
    cout << "Searching for '" << searchWord << "': "
        << (trie.search(searchWord) ? "Found\n" : "Not Found\n");

    // Remove a word
    trie.remove("car");

    // Display after deletion
    trie.display();

    return 0;
}
