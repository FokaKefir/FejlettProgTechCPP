#include <iostream>
#include "Point.h"
#include "Polynomial.h"

using namespace std;

int main() {
    double coeff1[] = {2.0, 5.0, 8.0};
    Polynomial pol1(2, coeff1);
    cout << pol1;

    double coeff2[] = {-1.0, 0, -2.0, -2};
    Polynomial pol2(3, coeff2);
    cout << pol2;

    Polynomial pol3 = pol1 + pol2;
    cout << pol3;

    Polynomial pol4 = pol3;
    cout << pol4;
    cout << -pol4;

    Polynomial pol5 = pol1 * pol2;
    cout << pol5;

    Polynomial pol6 = pol1.derivative();
    cout << pol6;

    cout << pol1;
    double x = 2;
    cout << "evaluate x=" << x << " f=" << pol1.evaluate(x) << endl;

    Polynomial pol7 = pol6.derivative();
    cout << pol6 << "*\n" << pol7;
    Polynomial pol8 = pol6 * pol7;
    cout << "= " << pol8;

}