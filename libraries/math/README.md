C++ Math Library Functions

C++ offers a rich set of mathematical functions in the <cmath> header file. These functions cover a wide range of operations, making it convenient to perform various calculations within your programs. Here's a detailed breakdown of the commonly used functions:

Basic Arithmetic

abs(x): Returns the absolute (non-negative) value of a number x.
Example: abs(-5.2) returns 5.2.
Rounding and Integral Conversions

ceil(x): Rounds a number x up to the nearest integer, always towards positive infinity.
Example: ceil(3.14) returns 4.
floor(x): Rounds a number x down to the nearest integer, always towards negative infinity.
Example: floor(3.14) returns 3.
round(x): Rounds a number x to the nearest integer, considering the decimal part.
Example: round(3.5) returns 4, while round(3.4) returns 3.
Power and Exponent

pow(x, y): Raises x to the power of y.
Example: pow(2, 3) returns 8.
Logarithms

exp(x): Returns the base-e (natural) exponent of x.
Example: exp(1) returns 2.71828....
log(x): Returns the natural logarithm (base-e) of x. Input value must be positive.
Example: log(2.71828...) returns 1.
log10(x): Returns the base-10 logarithm of x. Input value must be positive.
Example: log10(100) returns 2.
log2(x): Returns the base-2 logarithm of x. Input value must be positive.
Example: log2(8) returns 3.
Trigonometric Functions (Angles in Radians)

sin(x): Returns the sine of an angle x in radians.
Example: sin(PI/2) returns 1 (sine of 90 degrees).
cos(x): Returns the cosine of an angle x in radians.
Example: cos(PI) returns -1 (cosine of 180 degrees).
tan(x): Returns the tangent of an angle x in radians.
Example: tan(PI/4) returns 1 (tangent of 45 degrees).
Inverse Trigonometric Functions

asin(x): Returns the arc sine of x in radians. Input value must be between -1 and 1.
Example: asin(1) returns PI/2 (arcsine of 1).
acos(x): Returns the arc cosine of x in radians. Input value must be between -1 and 1.
Example: acos(-1) returns PI (arccosine of -1).
atan(x): Returns the arc tangent of x in radians.
Hyperbolic Functions

sinh(x): Returns the hyperbolic sine of x.
cosh(x): Returns the hyperbolic cosine of x.
tanh(x): Returns the hyperbolic tangent of x.
Other Functions

fmod(x, y): Returns the floating-point remainder of x / y.
Example: fmod(10.5, 2) returns 0.5.
sqrt(x): Returns the square root of a non-negative number x.
Example: sqrt(9) returns 3.
cbrt(x): Returns the cube root of a number x.
Example: cbrt(27) returns 3.
hypot(x, y): Returns the Euclidean distance, the square root of x^2 + y^2.
Example: hypot(3, 4) returns `5

Sources
github.com/mrkgnao/Expression
