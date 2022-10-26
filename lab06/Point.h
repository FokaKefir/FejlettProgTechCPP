#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

#include <math.h>
#include <iostream>
#define M 2000

class Point {
private:
    int x;
    int y;
    static int counter;
public:
    Point(int x=0, int y=0);
    Point(const Point &point);
    Point(Point &&point);
    ~Point();
    static int getCounter();
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point) const;
    void print() const;

    Point &operator=(const Point p);
};

#endif //CPP_2022_POINT_H
