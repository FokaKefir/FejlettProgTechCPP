#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 and x <= M and y >= 0 and y <= M) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow((point.getY() - this->getY()), 2) + pow((point.getX() - this->getX()), 2));
}

void Point::print() const {
    std::cout << "(" << x << " " << y << ")" << std::endl;
}


