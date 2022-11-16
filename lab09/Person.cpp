#include "Person.h"

Person::Person(const string &firstname, const string &lastname, int birthYear) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthYear = birthYear;
}

void Person::print(ostream &out) const {
    out << this->firstname << " " << this->lastname << " " << this->birthYear;
}

ostream &operator<<(ostream &out, const Person &person) {
    person.print(out);
    return out;
}


