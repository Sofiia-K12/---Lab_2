#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

struct Point {
    double x, y;
};

double distance(const Point &p1, const Point &p2);

struct Triangle {
    Point A, B, C;

    Triangle() = default;
    Triangle(Point a, Point b, Point c) : A(a), B(b), C(c) {}

    double cross(const Point &a, const Point &b, const Point &c) const; 
    double area() const;               
    bool isDegenerate() const;         
    bool onSegment(const Point &a, const Point &b, const Point &p) const;
    bool onBorder(const Point &p) const;

        
    bool containsVector(const Point &P) const;   
    bool containsHeron(const Point &P) const;    

private:
    double heronArea(const Point &a, const Point &b, const Point &c) const; 
};

#endif