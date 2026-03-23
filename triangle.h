#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

double distance(const Point &p1, const Point &p2);

struct Triangle {
    Point A, B, C;

    double area() const;
    double cross(const Point &a, const Point &b, const Point &c) const;

    bool isDegenerate() const;
    bool onSegment(const Point &a, const Point &b, const Point &p) const;
    bool onBorder(const Point &p) const;

    bool contains(const Point &P) const;        // через площі
    bool containsVector(const Point &P) const;  // через векторний добуток
};

#endif