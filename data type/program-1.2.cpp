#include <iostream>
#include <limits>

/*
C++ uses char data type to store characters, and its size can vary depending on the system (typically 1 byte). This byte can potentially hold a wider range of values (256 for an 8-bit byte).

Here are some key points to remember:

By default, char is signed in C++. This means it can hold values from -128 to 127 (assuming a 1-byte size).
You can use unsigned char to explicitly store non-negative values (0 to 255 for a 1-byte size).
The actual character displayed depends on the character set or encoding used by the system (not just ASCII).

*/
int main() {
    // Using <limits.h> header
    std::cout << "**Using <limits.h> header**\n";
    std::cout << "Size of byte: " << sizeof(char) << " byte(s)\n";
    std::cout << "Minimum value of byte: " << (int)CHAR_MIN << std::endl;  // Cast to int for display
    std::cout << "Maximum value of byte: " << (int)CHAR_MAX << std::endl;  // Cast to int for display

    std::cout << "\nMinimum value of short: " << SHRT_MIN << std::endl;
    std::cout << "Maximum value of short: " << SHRT_MAX << std::endl;

    std::cout << "\nMinimum value of int: " << INT_MIN << std::endl;
    std::cout << "Maximum value of int: " << INT_MAX << std::endl;

    std::cout << "\nMinimum value of long: " << LONG_MIN << std::endl;
    std::cout << "Maximum value of long: " << LONG_MAX << std::endl;

    // Using <numeric_limits> header (C++11 and later)
    std::cout << "\n**Using <numeric_limits> header**\n";
    std::cout << "Size of byte: " << sizeof(char) << " byte(s)\n";
    std::cout << "Minimum value of byte: " << std::numeric_limits<char>::min() << std::endl;
    std::cout << "Maximum value of byte: " << std::numeric_limits<char>::max() << std::endl;

    std::cout << "\nMinimum value of short: " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "Maximum value of short: " << std::numeric_limits<short>::max() << std::endl;

    std::cout << "\nMinimum value of int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum value of int: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "\nMinimum value of long: " << std::numeric_limits<long>::min() << std::endl;
    std::cout << "Maximum value of long: " << std::numeric_limits<long>::max() << std::endl;

    return 0;
}
