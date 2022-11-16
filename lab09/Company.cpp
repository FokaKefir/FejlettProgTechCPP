#include "Company.h"

void Company::addEmployee(Employee *e) {
    employees.push_back(e);
}

void Company::addEmployeeToManager(Manager *manager, Employee* employee) {
    manager->addEmployee(employee);

}

void Company::removeEmployeeFromManager(Manager *manager, Employee *employee) {
    manager->deleteEmployee(employee->getId());
}

void Company::printAll(ostream &out) const {
    out << "Employees:\n";
    for (auto emp : employees) {
        out << emp << endl;
    }
}

void Company::printManager(ostream &out) const {
    out << "Managers:\n";
    for (auto emp : employees) {
        Manager *manager = dynamic_cast<Manager*>(emp);
        if (manager != nullptr)
            out << emp << endl;
    }
}

void Company::removeEmployee(int id) {
    for (auto emp : employees) {
        Manager *manager = dynamic_cast<Manager*>(emp);
        if (manager != nullptr)
            manager->deleteEmployee(id);
    }

    auto it = find_if(this->employees.begin(), this->employees.end(), [&](const Employee* e){
        return e->getId() == id;
    });
    if (it != this->employees.end()) {
        this->employees.erase(it);
    }
}

