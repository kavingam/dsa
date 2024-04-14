#include <iostream>
#include <cfloat>
#include <limits>  // for basic range and size checks
//#include <numeric_limits> // for C++11 and later, more detailed information

template <typename T>
void checkDataTypeRangeAndByte() {
  // Get data type size in bytes
  std::size_t sizeInBytes = sizeof(T);

  // Using <limits.h> header (basic coverage)
  std::cout << "Data Type: " << typeid(T).name() << std::endl;
  std::cout << "Size: " << sizeInBytes << " byte(s)" << std::endl;
  std::cout << "Minimum value: " << std::numeric_limits<T>::min() << std::endl;
  std::cout << "Maximum value: " << std::numeric_limits<T>::max() << std::endl;

  // Using <numeric_limits> header (C++11 and later, more details)
  std::cout << "Is signed: " << std::numeric_limits<T>::is_signed << std::endl;
  std::cout << "Epsilon (smallest difference for floating-point): ";
  if (std::numeric_limits<T>::is_floating_point) {
    std::cout << std::numeric_limits<T>::epsilon() << std::endl;
  } else {
    std::cout << "N/A (not a floating-point type)" << std::endl;
  }

  std::cout << std::endl;
}

int main() {
  checkDataTypeRangeAndByte<int>();
  checkDataTypeRangeAndByte<char>();
  checkDataTypeRangeAndByte<float>();
  checkDataTypeRangeAndByte<double>();
  // You can call the function for any data type you want to check
}

