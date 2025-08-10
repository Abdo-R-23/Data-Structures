#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
    string data;

public:
    MyString() : data("") {} // Constructor ????
    MyString(const string& text) : data(text) {} // Constructor ???

    void append(const string& text) {
        data += text;
    }

    void insertAt(int index, const string& text) {
        if (index >= 0 && index <= data.size())
            data.insert(index, text);
    }

    void removeAt(int index, int length) {
        if (index >= 0 && index + length <= data.size())
            data.erase(index, length);
    }

    void print() const {
        cout << data << endl;
    }
};

int main() {
    MyString str("Hello");
    str.append(" World");
    str.print();

    str.insertAt(6, "Beautiful ");
    str.print();

    str.removeAt(6, 10);
    str.print();

    return 0;
}
