#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"

class Stack {
private:
    List lst;
public:
    Stack();
    ~Stack();
    void push(int e);
    int pop();
    bool isEmpty() const;
};


#endif //CPP_2022_STACK_H
