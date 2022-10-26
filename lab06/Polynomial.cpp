#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double[this->capacity];
    if (coefficients == nullptr)
        return;

    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete[] this->coefficients;
}

Polynomial::Polynomial(const Polynomial &pol) {
    this->capacity = pol.capacity;
    this->coefficients = new double[this->capacity];
    if (pol.coefficients == nullptr)
        return;
    for (int i = 0; i < this->capacity; ++i) {
        this->coefficients[i] = pol.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&pol) {
    this->capacity = pol.capacity;
    this->coefficients = pol.coefficients;
    pol.coefficients = nullptr;
}

int Polynomial::degree() const {
    return this->capacity - 1;
}

Polynomial Polynomial::derivative() const {
    Polynomial pol(this->capacity - 2, nullptr);
    for (int i = 0; i < pol.capacity; ++i) {
        pol.coefficients[i] = this->coefficients[i + 1] * (i + 1);
    }
    return pol;
}

double Polynomial::evaluate(double x) const {
    if (this->capacity == 0)
        return 0;
    double s = this->coefficients[0];
    double xn = x;
    for (int i = 1; i < this->capacity; ++i) {
        s += xn * this->coefficients[i];
        xn *= x;
    }
    return s;
}

double Polynomial::operator[](int index) const {
    if (index >= this->capacity or index < 0)
        return 0;
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &pol) {
    Polynomial res(pol.capacity, nullptr);
    for (int i = 0; i < res.capacity; ++i) {
        res.coefficients[i] = -1 * pol[i];
    }
    return res;
}

Polynomial operator+(const Polynomial &pol1, const Polynomial &pol2) {
    Polynomial res(max(pol1.capacity, pol2.capacity), nullptr);
    for (int i = 0; i < res.capacity; ++i) {
        res.coefficients[i] = pol1[i] + pol2[i];
    }
    return res;
}

Polynomial operator-(const Polynomial &pol1, const Polynomial &pol2) {
    Polynomial res(max(pol1.capacity, pol2.capacity), nullptr);
    for (int i = 0; i < res.capacity; ++i) {
        res.coefficients[i] = pol1[i] - pol2[i];
    }
    return res;
}

Polynomial operator*(const Polynomial &pol1, const Polynomial &pol2) {
    Polynomial res(pol1.capacity + pol2.capacity, nullptr);
    for (int i = 0; i < res.capacity; ++i) {
        res.coefficients[i] = 0;
    }
    for (int i = 0; i < pol1.capacity; ++i) {
        for (int j = 0; j < pol2.capacity; ++j) {
            res.coefficients[i + j] += pol1[i] * pol2[j];
        }
    }
    return res;
}

ostream &operator<<(ostream &os, const Polynomial &pol) {
    for (int i = pol.capacity - 1; i >= 1; i--) {
        if (pol[i] == 0)
            continue;
        if (pol[i] > 0)
            os << "+";
        os << pol[i] << "x^" << i;
    }
    if (pol[0] > 0)
        os << "+";
    os << pol[0] << endl;
    return os;
}


