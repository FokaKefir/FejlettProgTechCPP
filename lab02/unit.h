#ifndef CPP_2022_UNIT_H
#define CPP_2022_UNIT_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Point.h"

using namespace std;

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char *filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);

#endif //CPP_2022_UNIT_H
