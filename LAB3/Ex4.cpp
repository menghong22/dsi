#include <iostream>
#include <cmath> // For sqrt()
using namespace std;

void solveEquation(int a, int b, int c, float *x1, float *x2, float *delta) {
    *delta = (b * b) - (4 * a * c);

    if (*delta > 0) {
        *x1 = (-b + sqrt(*delta)) / (2 * a);
        *x2 = (-b - sqrt(*delta)) / (2 * a);
    } else if (*delta == 0) {
        *x1 = *x2 = -b / (2.0 * a);
    }
}

int main() {
    int a, b, c;
    float x1, x2, delta;

    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Error: 'a' cannot be zero in a quadratic equation." << endl;
    } else {
        solveEquation(a, b, c, &x1, &x2, &delta);

        cout << "Delta: " << delta << endl;
        if (delta >= 0) {
            cout << "x1: " << x1 << endl;
            cout << "x2: " << x2 << endl;
        } else {
            cout << "The equation has no real roots." << endl;
        }
    }

    return 0;
}