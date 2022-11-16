#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include "Employee.h"
#include <vector>
#include <algorithm>


class Manager : public Employee{
private:
    vector<Employee*> employees;
public:
    const static string MANAGER_DEPARTMENT;
    Manager(const string &firstname, const string &lastname, int byear, const string &department);
    void addEmployee(Employee* e);
    void deleteEmployee(int id);
    int numberOfEmployees() const;
    virtual void print(ostream &out) const override;

};


#endif //CPP_2022_MANAGER_H
