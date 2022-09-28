#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void print() const;
};

#endif //CPP_2022_POINT_H
