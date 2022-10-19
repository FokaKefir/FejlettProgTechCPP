#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

#include <math.h>
#include <iostream>
#define M 2000

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point) const;
    void print() const;
};

#endif //CPP_2022_POINT_H
