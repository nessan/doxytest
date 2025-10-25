# README

`Student.h` is a small class with several doctests containing deliberate errors.
You can generate the `doxy_Student.cpp` file with the command:

```sh
python3 ../../doxytest.py --force Student.h
```

which will print something like:

```txt
Generated test file: doxy_Student.cpp with 7 test cases.
```

Compile and run `doxy_Student.cpp`:

```sh
clang++ -std=c++23 -o doxy_Student doxy_Student.cpp
./doxy_Student
```

which will yield the output:

```txt
FAILED `assert_eq(john, jane)` [Student.h:67]
As expected, this failed
lhs = John Doe (1007)
rhs = Jane Doe (1008)

test 7/7 (Student.h:85) ... FAIL

FAILED `assert_eq(std::format("{}", student), "John Doe (1000)")` [Student.h:85]
This is a deliberate error!
lhs = John Doe (1009)
rhs = John Doe (1000)


Test FAIL summary for `Student.h`: Ran 7 of a possible 7 tests, PASSED: 5, FAILED: 2
--------------------------------------------------------------------------------------
FAILED `assert_eq(john, jane)` [Student.h:67]
As expected, this failed
lhs = John Doe (1007)
rhs = Jane Doe (1008)

FAILED `assert_eq(std::format("{}", student), "John Doe (1000)")` [Student.h:85]
This is a deliberate error!
lhs = John Doe (1009)
rhs = John Doe (1000)
```

## Error Free Equivalent

`ErrorFreeStudent.h` is the same source without the deliberate errors.

```sh
python3 ../../doxytest.py --force ErrorFreeStudent.h
```

which will print something like:

```txt
Generated test file: doxy_ErrorFreeStudent.cpp with 7 test cases.
```

Compile and run `doxy_ErrorFreeStudent.cpp`:

```sh
clang++ -std=c++23 -o doxy_ErrorFreeStudent doxy_ErrorFreeStudent.cpp
./doxy_ErrorFreeStudent
```

which will yield the output:

```txt
Running 7 tests extracted from: `ErrorFreeStudent.h`
test 1/7 (ErrorFreeStudent.h:11) ... pass
test 2/7 (ErrorFreeStudent.h:23) ... pass
test 3/7 (ErrorFreeStudent.h:32) ... pass
test 4/7 (ErrorFreeStudent.h:45) ... pass
test 5/7 (ErrorFreeStudent.h:56) ... pass
test 6/7 (ErrorFreeStudent.h:67) ... pass
test 7/7 (ErrorFreeStudent.h:85) ... pass
[ErrorFreeStudent.h] All 7 tests PASSED
```
