#include "Manager.h"

const string Manager::MANAGER_DEPARTMENT = "manager";

Manager::Manager(const string &firstname, const string &lastname, int byear, const string &department) :
    Employee(firstname, lastname, byear, department) {}

void Manager::addEmployee(Employee* e) {
    this->employees.push_back(e);
}

void Manager::deleteEmployee(int id) {
    auto it = find_if(this->employees.begin(), this->employees.end(), [&](const Employee* e){
        return e->getId() == id;
    });
    if (it != this->employees.end()) {
        this->employees.erase(it);
    }
}

int Manager::numberOfEmployees() const {
    return this->employees.size();
}

void Manager::print(ostream &out) const {
    Employee::print(out);
    cout << ":\n";
    int ind = 1;
    for(auto emp : this->employees) {
        out << "\t" << ind <<". ";
        emp->print(out);
        out << endl;
    }
}
