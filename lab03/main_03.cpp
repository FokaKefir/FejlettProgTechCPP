#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List lst = List();
    lst.insertFirst(1);
    lst.insertFirst(2);
    cout << lst.size() << endl;
    lst.insertFirst(3);
    lst.print();
    lst.removeFirst();
    cout << lst.size() << endl;
    lst.remove(2, List::DeleteFlag::LESS);
    lst.print();
    cout << lst.size() << endl;
    return 0;
}
