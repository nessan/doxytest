#include "calc/divide.h"
#include <stdexcept>

namespace calc {

/// @brief Divides two numbers.
///
/// Generally doctests are in header files but this one is in a source file just to show that it is possible.
/// See the `CMakeLists.txt` file where we get `doxytest.py` to also look at the .cpp file.
///
/// # Examples
/// ```
/// using namespace calc;
/// assert_eq(divide(8, 2), 4);
/// ```
int
divide(int a, int b) {
    if (b == 0) { throw std::runtime_error("Division by zero"); }
    return a / b;
}

} // namespace calc