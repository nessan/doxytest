#pragma once

namespace calc {

/// Adds two numbers.
///
/// # Examples
/// ```
/// using namespace calc;
/// assert_eq(add(1, 2), 3);
/// ```
constexpr int
add(int a, int b) {
    return a + b;
}

/// Subtracts two numbers.
///
/// # Examples
/// ```
/// using namespace calc;
/// assert_eq(subtract(1, 2), -1);
/// ```
constexpr int
subtract(int a, int b) {
    return a - b;
}

/// Multiplies two numbers.
///
/// # Examples
/// ```
/// using namespace calc;
/// assert_eq(multiply(1, 2), 2);
/// ```
constexpr int
multiply(int a, int b) {
    return a * b;
}

} // namespace calc