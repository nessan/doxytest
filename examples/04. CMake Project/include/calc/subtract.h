#pragma once

namespace calc {

/// @brief Subtracts two numbers.
///
/// # Examples
/// ```
/// using namespace calc;
/// assert_eq(subtract(1, 2), -1);
/// ```
int
subtract(int a, int b) {
    return a - b;
}
} // namespace calc