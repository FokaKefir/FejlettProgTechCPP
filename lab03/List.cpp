#include "List.h"

List::List() {
    this->first = nullptr;
    this->nodeCounter = 0;
}

List::~List() {
    this->nodeCounter = 0;
    while (this->first != nullptr) {
        Node *t = this->first;
        this->first = this->first->next;
        delete t;
    }
}

bool List::exists(int d) const {
    for (Node *n = this->first; n != nullptr; n = n->next) {
        if (n->value == d)
            return true;
    }
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    return this->nodeCounter == 0;
}

void List::insertFirst(int d) {
    this->first = new Node(d, this->first);;
    this->nodeCounter++;
}

int List::removeFirst() {
    if (empty())
        throw std::domain_error("Empty list");
    int val = this->first->value;
    Node *n = this->first;
    this->first = this->first->next;
    delete n;
    this->nodeCounter--;
    return val;
}

void List::remove(int d, List::DeleteFlag df) {
    Node *n = this->first;
    if ((df == DeleteFlag::EQUAL and d == n->value)
        || (df == DeleteFlag::LESS and n->value < d)
        || (df == DeleteFlag::GREATER and n->value > d)) {
        removeFirst();
        return;
    }
    Node *prev = n;
    n = n->next;
    while (n != nullptr) {
        if ((df == DeleteFlag::EQUAL and d == n->value)
            || (df == DeleteFlag::LESS and n->value < d)
            || (df == DeleteFlag::GREATER and n->value > d)) {
            prev->next = n->next;
            delete n;
            this->nodeCounter--;
            return;
        }
        prev = n;
        n = n->next;
    }
}

void List::print() const {
    for (Node *n = this->first; n != nullptr; n = n->next) {
        std::cout << n->value << " ";
    }
    std::cout << std::endl;
}
