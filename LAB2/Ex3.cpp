#include <iostream>

using namespace std;

// a. Recursive function to display n stars
void displayStar(int n) {
    if (n <= 0) {
        return; // Base case: stop when n reaches 0
    }
    cout << "*";
    displayStar(n - 1); // Recursive call
}

// b. Recursive function to display numbers from n down to 1
void displayNumbers(int n) {
    if (n <= 0) {
        return; // Base case: stop when n reaches 0
    }
    cout << n << " ";
    displayNumbers(n - 1); // Recursive call
}

int main() {
    int choice, n;

    // Infinite loop for the menu
    while (true) {
        cout << "\n\n--- Recursive Display Menu ---" << endl;
        cout << "1. Display n Stars (*)" << endl;
        cout << "2. Display numbers from n to 1" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program..." << endl;
            break; // Break the infinite loop
        }

        cout << "Enter the value for n: ";
        cin >> n;

        switch (choice) {
            case 1:
                cout << "Result: ";
                displayStar(n);
                cout << endl;
                break;
            case 2:
                cout << "Result: ";
                displayNumbers(n);
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}