#include <iostream>
#include <limits>

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
