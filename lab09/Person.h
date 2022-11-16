#ifndef CPP_2022_PERSON_H
#define CPP_2022_PERSON_H

#include <string>
#include<iostream>

using namespace std;

class Person {
protected:
    string firstname;
    string lastname;
    int birthYear;

public:
    Person(const string &firstname, const string &lastname, int birthYear);
    virtual void print(ostream &out) const;
};


#endif //CPP_2022_PERSON_H
