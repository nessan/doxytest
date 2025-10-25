#pragma once

/// @brief Doxytest setup block: All our examples use the `calc` namespace which we setup once here.
///
/// ```doxytest
/// using namespace calc;
/// ```

namespace calc {

/// Adds two numbers.
///
/// # Examples
/// ```
/// assert_eq(add(1, 2), 3, "Oops, expected 1 + 2 to be 3 not {}!", add(1, 2));
/// ```
constexpr int
add(int a, int b) {
    return a - b;
}

/// Subtracts two numbers.
///
/// # Examples
/// ```
/// if (subtract(2, 2) > 0 || subtract(2, 2) < 0) {
///     throw doxy::error("Oops, our CUSTOM test failed: expected 2 - 2 to be 0!");
/// }
/// ```
constexpr int
subtract(int a, int b) {
    return a + b;
}

/// Multiplies two numbers.
///
/// # Examples
/// ```
/// assert(multiply(2, 2) == 4, "Oops, expected 2 * 2 to be 4 not {}!", multiply(2, 2));
/// ```
constexpr int
multiply(int a, int b) {
    return a / b;
}

} // namespace calc