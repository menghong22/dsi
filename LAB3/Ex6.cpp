#include <iostream>
using namespace std;

int main() {
    float arr[7];
    float *ptr = arr; // Pointer referencing the array [cite: 7]

    cout << "Enter 7 float numbers: " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> *(ptr + i);
    }

    // a. Display numbers using another pointer
    float *displayPtr = arr;
    cout << "Stored numbers: ";
    for (int i = 0; i < 7; i++) {
        cout << *(displayPtr + i) << " ";
    }
    cout << endl;

    // b. Compute summation and multiplication [cite: 9]
    float sum = 0;
    float mult = 1;
    for (int i = 0; i < 7; i++) {
        sum += *(ptr + i);
        mult *= *(ptr + i);
    }

    cout << "Summation: " << sum << endl;
    cout << "Multiplication: " << mult << endl;

    return 0;
}