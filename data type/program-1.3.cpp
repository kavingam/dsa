#include <iostream>
#include <limits>
#include <cfloat>

int main() {
    // Using <limits.h> header (for basic coverage)
    std::cout << "**Using <limits.h> header**\n";
    std::cout << "Size of float: " << sizeof(float) << " byte(s)\n";
    std::cout << "Minimum value of float: " << FLT_MIN << std::endl;
    std::cout << "Maximum value of float: " << FLT_MAX << std::endl;

    std::cout << "\nSize of double: " << sizeof(double) << " byte(s)\n";
    std::cout << "Minimum value of double: " << DBL_MIN << std::endl;
    std::cout << "Maximum value of double: " << DBL_MAX << std::endl;

    // Using <numeric_limits> header (C++11 and later)
    std::cout << "\n**Using <numeric_limits> header**\n";
    std::cout << "Size of float: " << sizeof(float) << " byte(s)\n";
    std::cout << "Minimum representable value of float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Maximum representable value of float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Epsilon (smallest difference): " << std::numeric_limits<float>::epsilon() << std::endl;

    std::cout << "\nSize of double: " << sizeof(double) << " byte(s)\n";
    std::cout << "Minimum representable value of double: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Maximum representable value of double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Epsilon (smallest difference): " << std::numeric_limits<double>::epsilon() << std::endl;

    return 0;
}
