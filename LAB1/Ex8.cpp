#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// i) Celsius to Fahrenheit
double celToFah(double c) {
    return (c * 9.0 / 5.0) + 32;
}

// ii) Fahrenheit to Celsius
double fahToCel(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

// iii) Quadratic Equation Root
void findRoots(double a, double b, double c) {
    double discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        double r1 = (-b + sqrt(discriminant)) / (2*a);
        double r2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and different: " << r1 << " and " << r2 << endl;
    } else if (discriminant == 0) {
        cout << "Root is real and same: " << -b / (2*a) << endl;
    } else {
        cout << "Roots are complex/imaginary." << endl;
    }
}

// iv) BMI Calculator
void calculateBMI(double weight, double height) {
    double bmi = weight / (height * height);
    cout << "Your BMI is: " << bmi << " - ";
    if (bmi < 18.5) cout << "Underweight" << endl;
    else if (bmi < 25) cout << "Normal weight" << endl;
    else if (bmi < 30) cout << "Overweight" << endl;
    else cout << "Obese" << endl;
}

// v) Sum 1 to n skipping multiples of 3
int sumExcludeThree(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int choice;
    do {
        cout << "\n--- Engineering Utility Menu ---" << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "3. Quadratic Equation Solver" << endl;
        cout << "4. BMI Calculator" << endl;
        cout << "5. Sum 1 to n (skip multiples of 3)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double c; cout << "Enter Celsius: "; cin >> c;
                cout << "Fahrenheit: " << celToFah(c) << "°F" << endl;
                break;
            }
            case 2: {
                double f; cout << "Enter Fahrenheit: "; cin >> f;
                cout << "Celsius: " << fahToCel(f) << "°C" << endl;
                break;
            }
            case 3: {
                double a, b, c;
                cout << "Enter a, b, c: "; cin >> a >> b >> c;
                findRoots(a, b, c);
                break;
            }
            case 4: {
                double w, h;
                cout << "Enter weight (kg) and height (m): "; cin >> w >> h;
                calculateBMI(w, h);
                break;
            }
            case 5: {
                int n; cout << "Enter n: "; cin >> n;
                cout << "Sum: " << sumExcludeThree(n) << endl;
                break;
            }
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid option!" << endl;
        }
    } while (choice != 0);

    return 0;
}