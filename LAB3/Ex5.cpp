#include <iostream>
using namespace std;

void findMaxMin(int* arr, int *max, int *min) {
    // Initialize max and min with the first element
    *max = *arr;
    *min = *arr;

    for (int i = 1; i < 7; i++) {
        // Accessing elements using pointer arithmetic
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
    }
}

int main() {
    int numbers[7];
    int maxValue, minValue;

    cout << "Enter 7 integer numbers: " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> numbers[i];
    }

    // Pass the array and the addresses of maxValue and minValue
    findMaxMin(numbers, &maxValue, &minValue);

    cout << "Max: " << maxValue << endl;
    cout << "Min: " << minValue << endl;

    return 0;
}