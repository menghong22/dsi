#include <iostream>

using namespace std;

// a. Power function: m^n = m * m^(n-1)
int power(int m, int n) {
    if (n == 0) return 1; // Base case: any number to power 0 is 1
    return m * power(m, n - 1);
}

// b. Sum of squares: n^2 + (n-1)^2 + ... + 1^2
int sumSquare(int n) {
    if (n <= 1) return 1; // Base case: 1^2 is 1
    return (n * n) + sumSquare(n - 1);
}

// c. Sum of digits: 123 -> 3 + sumDigit(12)
int sumDigit(int n) {
    if (n == 0) return 0; // Base case: no more digits to add
    return (n % 10) + sumDigit(n / 10);
}

int main() {
    int m, n, num;

    // Test Power
    cout << "--- Power Function ---" << endl;
    cout << "Enter base (m) and exponent (n): ";
    cin >> m >> n;
    cout << m << "^" << n << " = " << power(m, n) << endl;

    // Test Sum of Squares
    cout << "\n--- Sum of Squares ---" << endl;
    cout << "Enter n: ";
    cin >> n;
    cout << "Sum of squares up to " << n << " is: " << sumSquare(n) << endl;

    // Test Sum of Digits
    cout << "\n--- Sum of Digits ---" << endl;
    cout << "Enter a multi-digit number: ";
    cin >> num;
    cout << "Sum of digits of " << num << " is: " << sumDigit(num) << endl;

    return 0;
}