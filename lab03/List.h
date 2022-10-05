#ifndef CPP_2022_LIST_H
#define CPP_2022_LIST_H

#include <stdexcept>
#include <iostream>


class List {
public:
    List();
    ~List();
    bool exists(int d) const;
    int size() const;
    bool empty() const;
    void insertFirst(int d);
    int removeFirst();
    enum class DeleteFlag {
        LESS, EQUAL, GREATER
    };
    void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);
    void print() const;
    List(const List&) = delete;
    List& operator=(const List&) = delete;

private:
    int nodeCounter{0};
    struct Node {
        int value;
        Node* next;

        Node(int v, Node* n) : value(v), next(n){}
    };
    Node *first;
};

#endif //CPP_2022_LIST_H
