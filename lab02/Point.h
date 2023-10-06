//
// Created by Alpar on 2023. 10. 04..
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H
#include<iostream>
#include<cmath>
#include<random>

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;

};
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);


Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
void closestPoints(Point* points, int numPoints);


#endif //CPP_2022_POINT_H
