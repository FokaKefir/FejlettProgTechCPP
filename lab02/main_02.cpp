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

int main() {
    testIsSquare("points.txt");
}

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
