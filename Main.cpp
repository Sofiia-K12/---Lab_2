#include <iostream>
#include "Triangle.h"
#include <windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(65001); 

    Point A, B, C, P;

    cout << "Введіть координати точки A (x y): ";
    cin >> A.x >> A.y;

    cout << "Введіть координати точки B (x y): ";
    cin >> B.x >> B.y;

    cout << "Введіть координати точки C (x y): ";
    cin >> C.x >> C.y;

    Triangle T(A, B, C);

    if (T.isDegenerate()) {

         cout << "Площа трикутника: " << T.area() << endl;
         
         cout << "Трикутник вироджений" << endl;
    } else {
        cout << "Трикутник НЕ вироджений" << endl;

        

        cout << "Введіть координати точки P (x y): ";
        cin >> P.x >> P.y;

    
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