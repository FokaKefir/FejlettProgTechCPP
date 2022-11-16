#ifndef CPP_2022_COMPANY_H
#define CPP_2022_COMPANY_H

#include "Manager.h"

class Company {
private:
    vector<Employee*> employees;
public:
    void addEmployee(Employee* e);
    void removeEmployee(int id);
    void addEmployeeToManager(Manager *manager, Employee* employee);
    void removeEmployeeFromManager(Manager *manager, Employee* employee);
    void printAll(ostream &out) const;
    void printManager(ostream &out) const;
};


#endif //CPP_2022_COMPANY_H
