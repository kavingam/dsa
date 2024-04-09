/*Using <numeric_limits> header (C++11 and later):*/
#include <iostream>
#include <numeric_limits>

int main() {
    std::cout << "Minimum value of int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum value of int: " << std::numeric_limits<int>::max() << std::endl;
    // Similar for other data types by replacing int with the desired type
}
