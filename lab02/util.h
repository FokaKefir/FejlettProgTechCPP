#ifndef CPP_2022_UTIL_H
#define CPP_2022_UTIL_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include "Point.h"

using namespace std;

double distance(const Point& a, const Point& b);
double distance(pair<Point, Point> points);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char *filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> closestPointsEffective(Point *points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);

#endif //CPP_2022_UTIL_H
