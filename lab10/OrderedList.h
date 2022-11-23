#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>

using namespace std;

template<class T, class LessComp=less<T>, class Equal=equal_to<T>>
class Iterator;

template<class T, class LessComp=less<T>, class Equal=equal_to<T>>
class OrderedList {
private:
    struct Node {
        T value;
        Node* next;
        Node(T v, Node* n) : value(v), next(n){}
    };
    Node* first;
    int numElements;
    friend class Iterator<T, LessComp, Equal>;

public:
    OrderedList() {
        this->first = nullptr;
        this->numElements = 0;
    }

    ~OrderedList() {
        while (first != nullptr) {
            Node* tmp = first;
            first = first->next;
            delete tmp;
        }
        this->numElements = 0;
    }

    bool isEmpty() const {
        return (this->numElements == 0);
    }

    void insert(const T &newValue) {
        if (first == nullptr) {
            first = new Node(newValue, nullptr);
        } else {
            Node* prev = nullptr;
            Node* act = this->first;
            LessComp less;
            while (act != nullptr and less(act->value, newValue)) {
                prev = act;
                act = act->next;
            }
            act = new Node(newValue, act);
            if (prev != nullptr)
                prev->next = act;
            else
                first = act;
        }
        this->numElements++;
    }

    void remove(T &value) {
        Node* prev = nullptr;
        Node* act = this->first;
        Equal e;
        while (act != nullptr) {
            if (e(act->value, value))
                break;
            prev = act;
            act = act->next;
        }
        if (act != nullptr) {
            if (prev == nullptr) {
                this->first = this->first->next;
                delete act;
            } else {
                prev->next = act->next;
                delete act;
            }
            this->numElements--;
        }
    }

    int size() const {
        return this->numElements;
    }

    bool find(T &value) const {
        Node* act = this->first;
        Equal e;
        LessComp less;
        while (act != nullptr) {
            if (e(act->value, value))
                return true;
            if (!less(act->value, value))
                return false;
            act = act->next;
        }
        return false;
    }

    void listItems(ostream &os) const {
        Node* act = this->first;
        while (act != nullptr) {
            os << act->value << " ";
            act = act->next;
        }
    }
};

template<class T, class LessComp, class Equal>
class Iterator {
private:
    OrderedList<T, LessComp, Equal> &list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &list) : list(list) {
        this->act = list.first;
    }
    bool hasNext() const {
        return (this->act != nullptr);
    }
    T next() {
        T &val = this->act->value;
        this->act = this->act->next;
        return val;
    }

};


#endif //CPP_2022_ORDEREDLIST_H
