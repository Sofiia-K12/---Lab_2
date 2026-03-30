#include <iostream>
#include "Triangle.h"
#include <windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(65001); 

    Point A, B, C;

    cout << "Введіть координати точки A (x y): ";
    cin >> A.x >> A.y;

    cout << "Введіть координати точки B (x y): ";
    cin >> B.x >> B.y;

    cout << "Введіть координати точки C (x y): ";
    cin >> C.x >> C.y;

    Triangle T(A, B, C);
    cout << "Площа трикутника: " << T.area() << endl;

    if (T.isDegenerate()) {
        cout << "Трикутник вироджений" << endl;
    } else {
        cout << "Трикутник НЕ вироджений" << endl;
    }

    int n;
    cout << "Введіть кількість точок: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point P;
        cout << "\nТочка " << i + 1 << " (x y): ";
        cin >> P.x >> P.y;

        if (T.onBorder(P))
            cout << "Точка лежить на межі трикутника" << endl;
        else
            cout << "Точка НЕ лежить на межі трикутника" << endl;

        if (T.containsVector(P))
            cout << "Точка належить трикутнику (векторний метод)" << endl;
        else
            cout << "Точка НЕ належить трикутнику (векторний метод)" << endl;

        if (T.containsHeron(P))
            cout << "Точка належить трикутнику (метод Герона)" << endl;
        else
            cout << "Точка НЕ належить трикутнику (метод Герона)" << endl;
    }

    return 0;
}