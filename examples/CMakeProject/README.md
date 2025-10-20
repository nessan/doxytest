# Sample CMake Project

This directory has some code for a sample "calculator" project that uses Doxytest and CMake.

The trivial sources are header-only and can be viewed in the `include/calc/` directory.

The `cmake/` subdirectory has the `doxytest.cmake` CMake module as well as the `doxytest.py` script that extracts doctests from header files.

In the governing `CMakeLists.txt` file you see code to locate the `doxytest.cmake` module which defines a single CMake function `doxytest`.
That is invoked as follows:

```cmake
doxytest(${CMAKE_SOURCE_DIR}/include/calc INCLUDES "<calc/calc.h>" LIBRARIES calc)
```

The function uses `doxytest.py` to extract doctests from all the headers in `include/calc/` and package them as test source code it puts in tyhe `doxytests/` directory.
Targets to build and run those tests are then made available. That includes a target for a combined test program `doxytests`.
