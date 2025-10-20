#pragma once

#include <string>
#include <format>

/// @brief This class represents a student with a name and a unique student ID.
///
/// Student ID's are incremented for each new student.
///
/// # Examples
/// ```
/// Student student_1{"John Doe"};
/// Student student_2{"Mary Doe"};
/// assert_eq(student_1.name(), "John Doe");
/// assert(student_2.name() == "Mary Doe");
/// assert_eq(student_2.id(), student_1.id() + 1, "Oops, expected student-ids to be consecutive!");
/// ```
class Student {
public:
    /// @brief Construct a new Student with the given `name`.
    ///
    /// # Examples
    /// ```
    /// Student student{"John Doe"};
    /// assert_eq(student.name(), "John Doe");
    /// ```
    Student(std::string_view name) : m_name(name), m_student_id(next_student_id++) {}

    /// @brief Provides read/write access to the student's name.
    ///
    /// # Examples
    /// ```
    /// Student student{"John Doe"};
    /// assert_eq(student.name(), "John Doe");
    /// auto id = student.id();
    /// student.name() = "Jane Doe";
    /// assert_eq(student.name(), "Jane Doe");
    /// assert_eq(student.id(), id);
    /// ```
    constexpr auto& name() { return m_name; }

    /// @brief Provides read-only access to the student's name.
    ///
    /// # Examples
    /// ```
    /// Student student{"John Doe"};
    /// assert_eq(student.name(), "John Doe");
    /// ```
    constexpr auto name() const { return m_name; }

    /// @brief Provides read-only access to the student's ID.
    ///
    /// Student ID's start at 1000 and are incremented for each new student.
    ///
    /// # Examples
    /// ```
    /// Student s1{"John Doe"};
    /// Student s2{"Jane Doe"};
    /// assert_eq(s2.id(), s1.id() + 1);
    /// ```
    constexpr auto id() const { return m_student_id; }

    /// @brief Compares two students for equality (only the ID matters).
    ///
    ///
    /// # Examples
    /// ```
    /// Student john{"John Doe"};
    /// Student jane{"Jane Doe"};
    /// assert_eq(john, john, "We're expecting this to pass!");
    /// assert_eq(jane, jane, "Corrected! This should pass!");
    /// ```
    constexpr bool operator==(const Student& other) const { return m_student_id == other.m_student_id; }

private:
    std::string m_name;
    std::size_t m_student_id;

    static inline std::size_t next_student_id = 1000;
};

/// @brief Specialise `std::formatter` for `Student`.
///
/// # Examples
/// ```
/// Student student{"John Doe"};
/// assert_eq(std::format("{}", student), "John Doe (1009)", "Corrected! This should pass!");
/// ```
template<>
struct std::formatter<Student> {
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const Student& student, FormatContext& ctx) const {
        return std::format_to(ctx.out(), "{} ({})", student.name(), student.id());
    }
};
