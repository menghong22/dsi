#include <iostream>
using namespace std;

// Function prototype as defined in the document [cite: 14]
void sum1(double *sum, int n) {
    *sum = 0; // Initialize the value at the pointer address
    for (int i = 1; i <= n; i++) {
        // Calculating 1 / (i * i)
        *sum += 1.0 / (i * i);
    }
}

int main() {
    double result;
    int n;

    cout << "Enter a positive integer n: ";
    cin >> n;

    // Pass the address of result and the value of n [cite: 21]
    sum1(&result, n);

    cout << "The sum is: " << result << endl;

    return 0;
}