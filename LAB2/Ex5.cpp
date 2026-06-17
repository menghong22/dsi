#include <iostream>

using namespace std;

// Recursive function to sum all array elements
int findSum(int a[], int n) {
    if (n <= 0) {
        return 0;
    }
    return a[n - 1] + findSum(a, n - 1);
}

int main() {
    int size;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    if (size < 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[size];
    if (size > 0) {
        cout << "Enter " << size << " integers:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    int totalSum = findSum(arr, size);
    cout << "\nThe total sum of the array elements is: " << totalSum << endl;

    return 0;
}