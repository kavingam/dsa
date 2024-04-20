#include <iostream>
#include <cstdlib> // for abs()

using namespace std;

int main() {
    int num1 = -10;
    double num2 = 5.7;

    cout << "Absolute value of " << num1 << " (integer): " << abs(num1) << endl;
    cout << "Absolute value of " << num2 << " (double): " << abs(num2) << endl;

    return 0;
}
