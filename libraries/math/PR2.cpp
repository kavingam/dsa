// Error Handling:
// Enhance the program to handle invalid user input (e.g., non-numeric characters):
#include <iostream>
#include <cstdlib>
#include <limits> // for numeric_limits

using namespace std;

int main() {
    int num;

    while (true) {
        cout << "Enter an integer: ";
        if (cin >> num) {
            // Valid input - break out of the loop
            break;
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            // Clear the input stream to handle future input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Absolute value of " << num << " is: " << abs(num) << endl;

    return 0;
}
