#include <iostream>
#include "Point.h"
#include "unit.h"

int main() {
    int n;
    cin >> n;
    Point* points = createArray(n);
    printArray(points, n);
    sortPoints(points, n);
    printArray(points, n);

    Point* fPoints = farthestPointsFromOrigin(points, n);
    printArray(fPoints, 10);

    deletePoints(points);
    deletePoints(fPoints);
}
