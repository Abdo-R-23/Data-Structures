#include <iostream>
using namespace std;
#include"ArrayList.h";

int main() {
    ArrayList<int> list;

    // ????? ????? ?? 1 ?? 100
    for (int i = 1; i <= 100; i++) {
        list.add(i);
    }

    cout << "Before deletion:\n";
    list.print();

    // ??? ?????? ?? index ??? 4
    list.removeAt(4);

    // ????? ????? 999 ??? index 2
    list.insert(2, 999);

    cout << "After operations:\n";
    list.print();

    return 0;
}
