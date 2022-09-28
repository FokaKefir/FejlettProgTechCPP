#include "unit.h"

double distance(const Point &a, const Point &b) {
    return sqrt(pow((a.getY() - b.getY()), 2) + pow((a.getX() - b.getX()), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    vector<double> distances = {
            distance(a, b),
            distance(b, c),
            distance(c, d),
            distance(d, a),
            distance(a, c),
            distance(b, d)
    };
    sort(distances.begin(), distances.end());
    if (distances[0] == distances[1] and distances[1] == distances [2] and distances[2] == distances[3]
        and distances[4] == distances[5] and distances[5] > distances[0])
        return true;
    return false;
}

void testIsSquare(const char *filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error opening file!\n";
        return;
    }

    while (!fin.eof()) {
        Point points[4];
        for (int i = 0; i < 4; ++i) {
            int x, y;
            fin >> x;
            fin >> y;
            points[i] = Point(x, y);

            cout << "P" << i;
            points[i].print();
            cout << ", ";
        }
        if (isSquare(points[0], points[1], points[2], points[3]))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    fin.close();
}

Point *createArray(int numPoints) {
    srand(time(0));
    Point* points = new Point[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(((int) rand()) % 2000, ((int) rand()) % 2000);
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
    cout << endl;
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if (numPoints < 2)
        return pair<Point, Point>(NAN, NAN);

    pair<Point, Point> cPoints(points[0], points[1]);
    double dis = distance(cPoints.first, cPoints.second);
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dis2 = distance(points[i], points[j]);
            if (dis2 < dis) {
                cPoints.first = points[i];
                cPoints.second = points[j];
            }
        }
    }
    return cPoints;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    if (numPoints < 2)
        return pair<Point, Point>(NAN, NAN);

    pair<Point, Point> fPoints(points[0], points[1]);
    double dis = distance(fPoints.first, fPoints.second);
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dis2 = distance(points[i], points[j]);
            if (dis2 > dis) {
                fPoints.first = points[i];
                fPoints.second = points[j];
            }
        }
    }
    return fPoints;
}

bool cmpPoints(const Point &a, const Point &b) {
    if (a.getX() == b.getX())
        return (a.getY() < b.getY());
    return (a.getX() < b.getX());
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, cmpPoints);
}

void deletePoints(Point *points) {
    delete[] points;
}

int findMinimumDistancesIndex(double* distances) {
    int ind = 0;
    for (int i = 1; i < 10; ++i) {
        if (distances[i] < distances[ind])
            ind = i;
    }
    return ind;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    Point origo;
    Point* fPoints = new Point[10];
    if (numPoints <= 10) {
        for (int i = 0; i < numPoints; ++i) {
            fPoints[i] = points[i];
        }
        for (int i = numPoints; i < 10; ++i) {
            fPoints[i] = Point();
        }
    } else {
        double distances[10] = {0};
        int minInd = 0;
        for (int i = 0; i < 10; ++i) {
            fPoints[i] = points[i];
            distances[i] = distance(origo, points[i]);
            if (distances[i] < distances[minInd])
                minInd = i;
        }
        for (int i = 10; i < numPoints; ++i) {
            double dis = distance(origo, points[i]);
            if (dis > distances[minInd]) {
                fPoints[minInd] = points[i];
                minInd = findMinimumDistancesIndex(distances);
            }
        }
    }
    return fPoints;
}


