#include <iostream>
#include "Company.h"

using namespace std;

int main() {
    Company company;
    Employee* e1 = new Employee("Nagy", "Sandor", 1996, "IT");
    Employee* e2 = new Employee("Nagy", "Elemer", 1996, "IT");
    Employee* e3 = new Employee("Acs", "Lajos", 1996, "ABC");
    Employee* e4 = new Employee("Kiss", "Pal", 1996, "ABC");
    Employee* e5 = new Employee("Kovacs", "Istvan", 1996, "IT");
    Employee* e6 = new Employee("Almos", "Almos", 1996, "Tech");
    Employee* e7 = new Employee("Szucs", "Imre", 1996, "Tech");

    Manager* m1 = new Manager("Boss", "Fonok", 1980);
    Manager* m2 = new Manager("Babos", "David", 2002);
    Manager* m3 = new Manager("Nem", "Csicska", 1900);

    Employee* emps[] = {e1, e2, e3, e4, e5, e6, e7, m1, m2, m3};
    for (int i = 0; i < 10; ++i) {
        company.addEmployee(emps[i]);
    }
    company.addEmployeeToManager(m1, e1);
    company.addEmployeeToManager(m1, e2);
    company.addEmployeeToManager(m1, e3);
    company.addEmployeeToManager(m2, e4);
    company.addEmployeeToManager(m2, e5);
    company.addEmployeeToManager(m2, e6);
    company.addEmployeeToManager(m3, e7);

    //company.printAll(cout);

    company.printManager(cout);

    company.removeEmployeeFromManager(m1, e1);
    company.addEmployeeToManager(m3, e1);

    company.printManager(cout);

    //company.deleteEmployee(e2->getId());
    //company.deleteEmployee(e3->getId());
    //company.printAll(cout);



    return 0;
}