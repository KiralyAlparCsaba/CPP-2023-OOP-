//
// Created by Alpar on 2023. 10. 18..
//

#include <cstdlib>
#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

PointSet::PointSet(int n) {
    this->n = n;

    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

    while (points.size() < n) {
        int x = dist(mt);
        int y = dist(mt);
        bool talalt = false;
        for (Point p : points) {
            if(p.getX() == x and p.getY() == y) {
                talalt = true;
                break;
            }
        }
        if(!talalt) {
            points.push_back(Point(x, y));
        }

    }
    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i+1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
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
    return distances.size();
}

void PointSet::printPoints() const {
    for (Point p : points) {
        cout << "(" << p.getX() << ", " << p.getY() << ")" << endl;
    }

}

void PointSet::printDistances() const {
    for (double d : distances) {
        cout << d << endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.getX() < p2.getX();
    });


}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.getY() < p2.getY();
    });

}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());

}

int PointSet::numDistinctDistances() {
    //return unique(distances.begin(), distances.end()) - distances.begin();
    vector<double> distances = this->distances;
    sort(distances.begin(), distances.end());
    auto uni = unique(distances.begin(), distances.end());
    return uni - distances.begin();
}
