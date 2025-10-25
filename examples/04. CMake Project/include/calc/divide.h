#pragma once

namespace calc {

/// @brief Divides two numbers.
///
/// This is implemented in `divide.cpp`.
/// Generally doctests are only in header files but `divide.cpp` also has a doctest to show that it is possible.
/// See the `CMakeLists.txt` file where we get `doxytest.py` to also look at the .cpp file.
///
/// # Examples
/// ```
/// using namespace calc;
/// assert_eq(divide(15, 3), 5);
/// ```
int divide(int a, int b);

} // namespace calc
