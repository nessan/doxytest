cmake_minimum_required(VERSION 3.31)

# Our example CMake project is a little library called 'calc'
project(calc DESCRIPTION "Example CMake project called 'calc'" LANGUAGES CXX)

# Add a target for the library we are building.
set(sources src/divide.cpp)
add_library(calc ${sources})

# We use C++23 features.
target_compile_features(calc PUBLIC cxx_std_23)

# Where to find the headers (how to resolve `#include <calc/calc.h>` or `#include "calc/calc.h"`).
target_sources(calc PUBLIC FILE_SET HEADERS BASE_DIRS include/)

# Include the doxytest.cmake module
include(cmake/doxytest.cmake)

# Extract the doctests and add build targets for the resulting test programs.
# Note: Generally we only have doctests in the header files but in this example we one in a source file.
doxytest(
    include/calc src/divide.cpp  # In this example we have doctests in the header and source files.
    EXTENSIONS h hpp cpp
    INCLUDES "<calc/calc.h>"     # We include the `calc.h` header file in all the test source files.
    LIBRARIES calc               # We link the test programs to the library we are building.
)
