#include "Stack.h"

Stack::Stack() {

}

Stack::~Stack() {

}

void Stack::push(int e) {
    this->lst.insertFirst(e);
}

int Stack::pop() {
    return this->lst.removeFirst();
}

bool Stack::isEmpty() const {
    return this->lst.empty();
}
