#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10; // ??? ??????
    list<pair<string, string>> table[SIZE]; // ?????? ?? Lists

    // ???? Hash
    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch; // ??? ????? ASCII
        }
        return hash % SIZE; // ???? ?????? ???? ??? index
    }

public:
    // ????? ????
    void insertItem(string key, string value) {
        int index = hashFunction(key);
        // ?? ??????? ?????? ???? ??????
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // ?? ?? ?????? ?????
        table[index].push_back({ key, value });
    }

    // ??? ????
    void removeItem(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    // ????? ?? ????
    string searchItem(string key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Not found";
    }

    // ??? ??????
    void displayTable() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto& pair : table[i]) {
                cout << "[" << pair.first << " : " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    // ????? ?????
    ht.insertItem("Ahmed", "01012345678");
    ht.insertItem("Mona", "01098765432");
    ht.insertItem("Khaled", "01111111111");
    ht.insertItem("Sara", "01234567890");

    // ??? ??????
    ht.displayTable();

    // ?????
    cout << "\nSearch Mona: " << ht.searchItem("Mona") << endl;

    // ???
    ht.removeItem("Ahmed");
    cout << "\nAfter removing Ahmed:\n";
    ht.displayTable();

    return 0;
}
