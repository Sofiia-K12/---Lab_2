#include <iostream>
#include <windows.h>
#include "Triangle.h"

using namespace std;

int main() {
    
    SetConsoleOutputCP(65001);

    Triangle t;

    cout << "Введіть координати трикутника:\n";
    cout << "A (x y): ";
    cin >> t.A.x >> t.A.y;
    cout << "B (x y): ";
    cin >> t.B.x >> t.B.y;
    cout << "C (x y): ";
    cin >> t.C.x >> t.C.y;

    if (t.isDegenerate()) {
        cout << "Трикутник вироджений. Програма завершена.\n";
        return 0;
    }

    int n;
    cout << "Скільки точок перевірити: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cout << "\nТочка " << i + 1 << " (x y): ";
        cin >> p.x >> p.y;

    
        if (t.contains(p))
            cout << "Через площі: належить трикутнику\n";
        else
            cout << "Через площі: не належить трикутнику\n";

       
        if (t.containsVector(p))
            cout << "Через векторний добуток: належить трикутнику\n";
        else
            cout << "Через векторний добуток: не належить трикутнику\n";
            if (t.onBorder(p))
            cout << "На межі трикутника: так\n";
        else
            cout << "На межі трикутника: ні\n";
    }

    return 0;
}