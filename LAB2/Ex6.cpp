#include <iostream>

using namespace std;

int askAndSum() {
    int num;
    cout << "Enter number : ";
    cin >> num;

    if (num == -1) {
        return 0;
    }
    return num + askAndSum();
}

int main() {
    int total = askAndSum();

    cout << "Total = " << total << endl;

    return 0;
}