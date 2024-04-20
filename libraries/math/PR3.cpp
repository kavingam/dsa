/*
#Alternative Implementation (Double and Conditional Statement):
#Demonstrate calculating the absolute value without abs():
*/
#include <iostream>

using namespace std;

int main() {
    double num;

    cout << "Enter a number (integer or double): ";
    cin >> num;

    int absNum = (num >= 0) ? static_cast<int>(num) : static_cast<int>(-num);

    cout << "Absolute value of " << num << " is: " << absNum << endl;

    return 0;
}
