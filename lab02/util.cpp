#include "util.h"

double distance(const Point &a, const Point &b) {
    return sqrt(pow((a.getY() - b.getY()), 2) + pow((a.getX() - b.getX()), 2));
}

double distance(pair<Point, Point> points) {
    return distance(points.first, points.second);
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
                dis = dis2;
            }
        }
    }
    return cPoints;
}

int cmpX(const void* a, const void* b){
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->getX() != p2->getX()) ? (p1->getX() - p2->getX()) : (p1->getY() - p2->getY());
}
int cmpY(const void* a, const void* b){
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->getY() != p2->getY()) ? (p1->getY() - p2->getY()) : (p1->getX() - p2->getX());
}

pair<Point, Point> recClosest(Point *xPoints, Point *yPoints, int numPoints) {
    if (numPoints <= 3)
        return closestPoints(xPoints, numPoints);

    int mid = numPoints / 2;
    Point midPoint = xPoints[mid];

    Point yPointsLeft[mid];
    Point yPointsRight[numPoints - mid];
    int indLeft = 0, indRight = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (yPoints[i].getX() < midPoint.getX() || (yPoints[i].getX() == midPoint.getX() && yPoints[i].getY() < midPoint.getY()) && indLeft < mid)
            yPointsLeft[indLeft++] = yPoints[i];
        else
            yPointsRight[indRight] = yPoints[i];
    }

    pair<Point, Point> pLeft = recClosest(xPoints, yPointsLeft, mid);
    pair<Point, Point> pRight = recClosest(xPoints + mid, yPointsRight, numPoints - mid);
    double dLeft = distance(pLeft);
    double dRight = distance(pRight);

    double dis;
    pair<Point, Point> pClosest;
    if (dLeft < dRight) {
        pClosest = pLeft;
        dis = dLeft;
    } else {
        pClosest = pRight;
        dis = dRight;
    }

    Point bandPoints[numPoints];
    int numBand = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (abs(yPoints[i].getX() - midPoint.getX()) < dis)
            bandPoints[numBand++] = yPoints[i];
    }

    for (int i = 0; i < numBand; ++i) {
        for (int j = i + 1; j < min(i + 7, numBand); ++j) {
            double d = distance(bandPoints[i], bandPoints[j]);
            if (d < dis) {
                pClosest = pair<Point, Point>(bandPoints[i], bandPoints[j]);
                dis = d;
            }
        }
    }

    return pClosest;
}

pair<Point, Point> closestPointsEffective(Point *points, int numPoints) {
    Point px[numPoints];
    Point py[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        px[i] = py[i] = points[i];
    }

    qsort(px, numPoints, sizeof(Point), cmpX);
    qsort(py, numPoints, sizeof(Point), cmpY);

    return recClosest(px, py, numPoints);
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


pair<Point, Point> recFarthest(Point *xPoints, Point *yPoints, int numPoints) {
    if (numPoints <= 3)
        return farthestPoints(xPoints, numPoints);

    int mid = numPoints / 2;
    Point midPoint = xPoints[mid];

    Point yPointsLeft[mid];
    Point yPointsRight[numPoints - mid];
    int indLeft = 0, indRight = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (yPoints[i].getX() < midPoint.getX() || (yPoints[i].getX() == midPoint.getX() && yPoints[i].getY() < midPoint.getY()) && indLeft < mid)
            yPointsLeft[indLeft++] = yPoints[i];
        else
            yPointsRight[indRight] = yPoints[i];
    }

    pair<Point, Point> pLeft = recFarthest(xPoints, yPointsLeft, mid);
    pair<Point, Point> pRight = recFarthest(xPoints + mid, yPointsRight, numPoints - mid);
    double dLeft = distance(pLeft);
    double dRight = distance(pRight);

    double dis;
    pair<Point, Point> pFarther;
    if (dLeft > dRight) {
        pFarther = pLeft;
        dis = dLeft;
    } else {
        pFarther = pRight;
        dis = dRight;
    }

    Point bandPoints[numPoints];
    int numBand = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (abs(yPoints[i].getX() - midPoint.getX()) > dis)
            bandPoints[numBand++] = yPoints[i];
    }

    for (int i = 0; i < numBand; ++i) {
        for (int j = i + 1; j < min(i + 7, numBand); ++j) {
            double d = distance(bandPoints[i], bandPoints[j]);
            if (d > dis) {
                pFarther = pair<Point, Point>(bandPoints[i], bandPoints[j]);
                dis = d;
            }
        }
    }

    return pFarther;
}

pair<Point, Point> farthestPointsEffective(Point *points, int numPoints) {
    Point px[numPoints];
    Point py[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        px[i] = py[i] = points[i];
    }

    qsort(px, numPoints, sizeof(Point), cmpX);
    qsort(py, numPoints, sizeof(Point), cmpY);

    return recClosest(px, py, numPoints);
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


