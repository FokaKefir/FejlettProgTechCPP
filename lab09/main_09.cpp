#include <iostream>
#include "Manager.h"

using namespace std;

ostream &operator<<(ostream &out, const Person &person);


int main() {


    return 0;
}

ostream &operator<<(ostream &out, const Person &person) {
    person.print(out);
    return out;
}