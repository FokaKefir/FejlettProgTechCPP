#include <iostream>
#include "Point.h"
#include "util.h"

int main() {
    /*
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
     */
    Point points[] = {
            Point(2, 3),
            Point(12, 30),
            Point(40, 50),
            Point(5, 1),
            Point(12, 10),
            Point(3, 4)
    };
    int n = 6;
    printArray(points, n);
    pair<Point, Point> cPoints = closestPoints(points, n);
    cPoints.first.print();
    cPoints.second.print();
    cout << distance(cPoints) << endl;

    pair<Point, Point> cPointsEff = closestPointsEffective(points, n);
    cPointsEff.first.print();
    cPointsEff.second.print();
    cout << distance(cPointsEff) << endl;
}
