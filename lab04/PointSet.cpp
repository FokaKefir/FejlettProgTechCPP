#include "PointSet.h"

PointSet::PointSet(int n) : n(n) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

    bool *table = new bool[M * M];
    while (this->points.size() < n) {
        Point p(dist(mt), dist(mt));
        if (table[p.getX() + M * p.getY()] == 0) {
            this->points.push_back(p);
            table[p.getX() + M * p.getY()] = true;
        }
    }
    computeDistances();
    delete[] table;
}

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            this->distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return this->distances.size();
}

void PointSet::printPoints() const {
    for (Point p : this->points) {
        p.print();
    }
}

void PointSet::printDistances() const {
    for (int dis : this->distances) {
        cout << dis << " ";
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b){
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b){
        return a.getY() - b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    vector<double> dists = this->distances;
    auto u = unique(dists.begin(), dists.end());
    return u - dists.begin();
}

