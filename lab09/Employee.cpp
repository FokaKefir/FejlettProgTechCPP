#include "Employee.h"

int Employee::count = 1;

void Employee::print(ostream &out) const {
    out << id << " ";
    Person::print(out);
    out << " " << department;
}

Employee::Employee(const string &firstname, const string &lastname, int byear, const string &department) :
    Person(firstname, lastname, byear), department(department), id(count++){}

int Employee::getId() const {
    return this->id;
}


