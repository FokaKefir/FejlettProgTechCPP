#include <iostream>
#include "List.h"
#include "Stack.h"
using namespace std;

int main() {
    List list = List();
    list.insertFirst(1);
    list.insertFirst(2);
    cout << "List size " << list.size() << endl;
    list.insertFirst(3);
    list.print();
    list.removeFirst();
    cout << "List size " << list.size() << endl;
    list.remove(2, List::DeleteFlag::LESS);
    list.print();
    cout << "List size " << list.size() << endl << endl;

    Stack stack = Stack();
    stack.push(1);
    stack.push(2);
    cout << (stack.isEmpty() == 1 ? "Stack is empty" : "Stack is not empty") << endl;
    cout << stack.pop() << endl;
    cout << (stack.isEmpty() == 1 ? "Stack is empty" : "Stack is not empty") << endl;
    cout << stack.pop() << endl;
    cout << (stack.isEmpty() == 1 ? "Stack is empty" : "Stack is not empty") << endl;
    try {
        cout << stack.pop() << endl;
    } catch (exception ex) {
        cout << ex.what();
    }
    return 0;
}
