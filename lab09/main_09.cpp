#include <iostream>
#include "Manager.h"

using namespace std;

ostream &operator<<(ostream &out, const Person &person);


int main() {
    Employee e1("Magyari", "Csaba", 2002, "Rabszolga");
    cout << e1 << " " << e1.getId() << endl;
    Employee e2("Fazakas", "Nimrod", 2002, "Rabszolga2");
    cout << e2 << " " << e2.getId() << endl;

    return 0;
}

ostream &operator<<(ostream &out, const Person &person) {
    person.print(out);
    return out;
}