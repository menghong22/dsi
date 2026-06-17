#include <iostream>
#include <algorithm> // For the min() function

using namespace std;

// Recursive function to find the minimum element
int findMin(int a[], int n) {
    if (n == 1) {
        return a[0];
    }
    return min(a[n - 1], findMin(a, n - 1));
}

int main() {
    int size;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int minimum = findMin(arr, size);
    cout << "\nThe minimum element in the array is: " << minimum << endl;

    return 0;
}