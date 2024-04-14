/*
Signed Integers:

Representation: They use a sign bit (typically the most significant bit) to indicate positive or negative values.
Range: The range depends on the data type size (e.g., int, short, long). For an n-bit signed integer:
Minimum value: -(2^(n-1)) (due to the negative sign)
Maximum value: 2^(n-1) - 1 (one less than the positive limit)
Example: An 8-bit signed integer can hold values from -128 to 127.
Use cases: When you need to represent both positive and negative numbers, such as:
Coordinates (X and Y positions)
Temperatures (can be above or below zero)
Counters that can increase or decrease

Unsigned Integers:
Representation: They don't have a sign bit, so all bits are used to represent the magnitude (non-negative value).
Range: The range for an n-bit unsigned integer is 0 to 2^n - 1.
Example: An 8-bit unsigned integer can hold values from 0 to 255.
Use cases: When you only need to represent non-negative values, such as:
Array or list indexes (always start from 0)
Percentages (range from 0% to 100%)
Sizes or counts that are always positive (e.g., number of elements in an array)
Key Differences and Considerations:

Overflow: Be cautious with arithmetic operations on signed integers. If the result exceeds the maximum positive or minimum negative value, overflow occurs. The behavior is implementation-defined (might wrap around or cause undefined results). Unsigned integers avoid this issue for positive values, but calculations might reach the maximum value (2^n - 1) and wrap around to 0.
Type Conversions: Mixing signed and unsigned types in expressions can lead to unexpected behavior due to implicit conversions. It's generally recommended to be explicit with casting when necessary.
Choice of Type: Select the appropriate type based on the expected range of values you need to represent.
*/

#include <iostream>
#include <limits>

int main() {
    int signed_num = -5;
    unsigned int unsigned_num = 10;

    // Arithmetic operations
    int result1 = signed_num + unsigned_num; // result1 will be 5 (positive)
    int result2 = signed_num - unsigned_num; // result2 will be -15 (negative)

    // Overflow example (assuming 8-bit signed integer)
    signed_num = 127;
    signed_num++;  // Overflow! result might be -128 (implementation-defined)

    std::cout << result1 << "\n";
    std::cout << result2 << "\n";

    return 0;
}

