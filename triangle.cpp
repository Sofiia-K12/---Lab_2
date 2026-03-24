#include "Triangle.h"
#include <algorithm>
#include <cmath>

using namespace std;


double Triangle::cross(const Point &a, const Point &b, const Point &c) const {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


double Triangle::area() const {
    return abs(cross(A, B, C)) / 2.0;
}


bool Triangle::isDegenerate() const {
    return abs(cross(A, B, C)) < 1e-9;
}

bool Triangle::onSegment(const Point &a, const Point &b, const Point &p) const {
    double c = cross(a, b, p);
    if (abs(c) > 1e-9
) return false;
    return (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
            p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y));
}

bool Triangle::onBorder(const Point &p) const {
    return onSegment(A, B, p) || onSegment(B, C, p) || onSegment(C, A, p);
}


bool Triangle::containsVector(const Point &P) const {
    if (isDegenerate()) return false;

    double c1 = cross(A, B, P);
    double c2 = cross(B, C, P);
    double c3 = cross(C, A, P);

    bool allPositive = (c1 >= -1e-9 && c2 >= -1e-9 && c3 >= -1e-9);
    bool allNegative = (c1 <= 1e-9 && c2 <= 1e-9 && c3 <= 1e-9);

    return allPositive || allNegative;
}

double Triangle::heronArea(const Point &a, const Point &b, const Point &c) const {
    double ab = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
    double bc = sqrt((c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y));
    double ca = sqrt((a.x - c.x)*(a.x - c.x) + (a.y - c.y)*(a.y - c.y));
    double s = (ab + bc + ca) / 2.0;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

bool Triangle::containsHeron(const Point &P) const {
    if (isDegenerate()) return false;        
    if (onBorder(P)) return true;            

    double S_main = heronArea(A, B, C);

    
    if (S_main < 1e-6) {
        
        double xmin = min({A.x, B.x, C.x});
        double xmax = max({A.x, B.x, C.x});
        double ymin = min({A.y, B.y, C.y});
        double ymax = max({A.y, B.y, C.y});

        return (P.x >= xmin && P.x <= xmax && P.y >= ymin && P.y <= ymax);
    }


    double S1 = heronArea(A, B, P);
    double S2 = heronArea(B, C, P);
    double S3 = heronArea(C, A, P);

    return abs(S_main - (S1 + S2 + S3)) < 1e-9;
}