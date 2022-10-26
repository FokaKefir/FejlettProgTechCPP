#ifndef CPP_2022_POLYNOMIAL_H
#define CPP_2022_POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial {
private:
    double *coefficients;
    int capacity;

public:
    Polynomial(int degree, const double coefficients[]);
    Polynomial(const Polynomial &pol);
    Polynomial(Polynomial &&pol);
    ~Polynomial();

    int degree() const;
    double evaluate(double x) const;
    Polynomial derivative() const;

    double operator[](int index) const;
    friend Polynomial operator-(const Polynomial &pol);
    friend Polynomial operator+(const Polynomial &pol1, const Polynomial &pol2);
    friend Polynomial operator-(const Polynomial &pol1, const Polynomial &pol2);
    friend Polynomial operator*(const Polynomial &pol1, const Polynomial &pol2);

    friend ostream &operator<<(ostream &os, const Polynomial &pol);

    Polynomial &operator=(const Polynomial &) = delete;
    Polynomial &operator=(Polynomial &&) = delete;

};


#endif //CPP_2022_POLYNOMIAL_H
