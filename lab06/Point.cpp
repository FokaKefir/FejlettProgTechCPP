#include "Point.h"

int Point::counter = 0;

Point::Point(int x, int y) {
    if (x >= 0 and x <= M and y >= 0 and y <= M) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
    counter++;
}

Point::Point(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    counter++;
}


Point::Point(Point &&point) {
    this->x = point.x;
    this->y = point.y;
    counter++;
}

Point::~Point() {
    this->x = this->y = 0;
    counter--;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::getCounter() {
    return counter;
}


double Point::distanceTo(const Point &point) const {
    return sqrt(pow((point.getY() - this->getY()), 2) + pow((point.getX() - this->getX()), 2));
}

void Point::print() const {
    std::cout << "(" << x << " " << y << ")" << std::endl;
}

Point &Point::operator=(const Point p) {
    this->x = p.x;
    this->y = p.y;
    return *this;
}





