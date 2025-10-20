# README

`calc.h` is a header with several (trivial) functions in their own namespace.
All the functions have doctests.
In this file we show one way to handle namespaces (every doctest has its own `using` statement).

Generate the test program source file `doxy_calc.cpp` as follows:

```sh
python3 ../../doxytest.py --force calc.h
```

Then compile and run that file:

```sh
g++ -std=c++23 -o doxy_calc doxy_calc.cpp
./doxy_calc
```

which will yield the output:

```txt
Running 3 tests extracted from: `calc.h`
test 1/3 (calc.h:8) ... pass
test 2/3 (calc.h:20) ... pass
test 3/3 (calc.h:32) ... pass
[calc.h] All 3 tests PASSED
```

## The Version with Errors

`oops.h` is the same code but with several deliberate errors.

This version also demonstrates

-   The use of a `doxytest` marked fenced code block to set up the `using calc;` just once.
-   The use of some custom test logic throwing a `doxy::error` on fails.

Generate the test program source file `doxy_oops.cpp`:

```sh
python3 ../../doxytest.py --force oops.h
```

Then compile and run it:

```sh
g++ -std=c++23 -o doxy_oops doxy_oops.cpp
./doxy_oops
```

which will yield the output:

```txt
Running 3 tests extracted from: `oops.h`
test 1/3 (oops.h:14) ... FAIL

FAILED `assert_eq(add(1, 2), 3)` [oops.h:14]
Oops, expected 1 + 2 to be 3 not -1!
lhs = -1
rhs = 3

test 2/3 (oops.h:25) ... FAIL
Oops, our CUSTOM test failed: expected 2 - 2 to be 0!
test 3/3 (oops.h:38) ... FAIL

FAILED `assert(multiply(2, 2) == 4)` [oops.h:38]
Oops, expected 2 * 2 to be 4 not 1!


Test FAIL summary for `oops.h`: Ran 3 of a possible 3 tests, PASSED: 0, FAILED: 3
--------------------------------------------------------------------------------------
FAILED `assert_eq(add(1, 2), 3)` [oops.h:14]
Oops, expected 1 + 2 to be 3 not -1!
lhs = -1
rhs = 3
Oops, our CUSTOM test failed: expected 2 - 2 to be 0!
FAILED `assert(multiply(2, 2) == 4)` [oops.h:38]
Oops, expected 2 * 2 to be 4 not 1!
```

Note that the second test did not use our `assert` or `assert_eq` macros but still integrated correctly with the Doxytest framework.
