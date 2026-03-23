#include "Triangle.h"
#include <cmath>
#include <algorithm>

using namespace std;

double Triangle::cross(const Point &a, const Point &b, const Point &c) const {
    return (b.x - a.x) * (c.y - a.y) -
           (b.y - a.y) * (c.x - a.x);
}

double Triangle::area() const {
    return abs(cross(A, B, C)) / 2.0;
}


bool Triangle::isDegenerate() const {
    return abs(cross(A, B, C)) < 1e-6;
}

// Перевірка, чи точка лежить на відрізку
bool Triangle::onSegment(const Point &a, const Point &b, const Point &p) const {
    double c = cross(a, b, p);

    if (abs(c) > 1e-6) return false;

    return (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
            p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y));
}


bool Triangle::onBorder(const Point &p) const {
    return onSegment(A, B, p) ||
           onSegment(B, C, p) ||
           onSegment(C, A, p);
}

// через площі 
bool Triangle::contains(const Point &P) const {
    if (isDegenerate()) return false;

    if (onBorder(P)) return true;

    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return abs(S_main - S_sum) < 1e-9;
}

// через векторний добуток
bool Triangle::containsVector(const Point &P) const {
    if (isDegenerate()) return false;

    double c1 = cross(A, B, P);
    double c2 = cross(B, C, P);
    double c3 = cross(C, A, P);

    bool allPositive = (c1 >= -1e-9 && c2 >= -1e-9 && c3 >= -1e-9);
    bool allNegative = (c1 <= 1e-9 && c2 <= 1e-9 && c3 <= 1e-9);

    return allPositive || allNegative;
}