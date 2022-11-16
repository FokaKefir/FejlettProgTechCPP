#ifndef CPP_2022_EMPLOYEE_H
#define CPP_2022_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    string department;
    int id;
    static int count;
public:
    Employee(const string &firstname, const string &lastname, int byear, const string &department);
    virtual void print(ostream &out) const override;
    int getId() const;
};


#endif //CPP_2022_EMPLOYEE_H
