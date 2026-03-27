#include <iostream>

using namespace std;

int sumOdd(int n) {
    if (n < 1) {
        return 0;
    }

    if (n % 2 != 0) {
        // If n is odd, add it and look for the next odd (n-2)
        return n + sumOdd(n - 2);
    } else {
        // If n is even, skip it and look at (n-1)
        return sumOdd(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter a number (n): ";
    cin >> n;

    int result = sumOdd(n);
    cout << "The sum of all odd numbers from 1 to " << n << " is: " << result << endl;

    return 0;
}