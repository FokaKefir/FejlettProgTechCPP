#include "Person.h"

void Person::print(ostream &out) const {
    out << this->firstname << " " << this->lastname << " " << this->birthYear;
}

Person::Person(const string &firstname, const string &lastname, int birthYear) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthYear = birthYear;
}

