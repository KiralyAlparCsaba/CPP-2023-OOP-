//
// Created by Alpar on 2023. 10. 04..
//

#include <algorithm>
#include <fstream>
#include <sstream>
#include<string.h>
#include "Point.h"
using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    cout<<"("<<x<<","<<y<<")"<<endl;

}

double distance(const Point &a, const Point &b) {
    int dx = a.getX() - b.getX();
    int dy = a.getY() - b.getY();
    return sqrt(dx*dx+dy*dy);
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double D[6]{
            distance(a, b),
            distance(a, c),
            distance(a, d),
            distance(b, c),
            distance(b, d),
            distance(d, c)
    };
    sort(D, D+6);
    if(D[0] != D[3] || D[5] != D[4] && D[3] >= D[4]){
        return false;
    }
    else{
        return true;
    }
}

void testIsSquare(const char *filename) {

    ifstream f(filename);
    if(!f){
        cout<<"Nincs file"<<endl;
        exit(0);
    }
    int x, y;
    string line;
    while(getline(f,line)) {
        stringstream ss(line);
        ss >> x >> y;
        Point p0(x,y);
        ss >> x >> y;
        Point p1(x,y);
        ss >> x >> y;
        Point p2(x,y);
        ss >> x >> y;
        Point p3(x,y);

        if (isSquare(p0, p1, p2, p3)) {
            cout << "square" << endl;
        } else {
            cout << "not square haha" << endl;
        }
    }
}

Point* createArray(int numPoints){;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 2000);
    Point * points = new Point[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(dist(gen), dist(gen));

    }
    return points;

}

void printArray(Point* points, int numPoints){
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
}

void closestPoints(Point* points, int numPoints){
    Point closest= points[0];
    int pos=0;
    for (int i = 1; i < numPoints; ++i) {
        if(distance(points[i].getX(),(points[i].getY()))<distance(closest.getX(),(closest.getY()))){
            closest = points[i];
            pos=i;
        }

    }
    cout<<"Closest point : "<<closest.getX()<<" "<<closest.getY()<<" and it's index :"<<pos<<endl;

}


