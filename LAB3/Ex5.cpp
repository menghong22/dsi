#include <iostream>
using namespace std;

void findMaxMin(int* arr, int *max, int *min) {
    *max = *arr;
    *min = *arr;

    for (int i = 1; i < 7; i++) {

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

    findMaxMin(numbers, &maxValue, &minValue);

    cout << "Max: " << maxValue << endl;
    cout << "Min: " << minValue << endl;

    return 0;
}