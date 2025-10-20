cmake_minimum_required(VERSION 3.31)

# Our example CMake project ...
project(calc DESCRIPTION "Example CMake project called 'calc'" LANGUAGES CXX)

# Add a target for the "library" we are building which is header only, hence INTERFACE.
add_library(calc INTERFACE)

# We use C++23 features.
target_compile_features(calc INTERFACE cxx_std_23)

# Where to find the headers (how to resolve `#include <calc/calc.h>`).
target_sources(calc INTERFACE
    FILE_SET    library_headers
    TYPE        HEADERS
    BASE_DIRS   include/)

# Include the doxytest.cmake module
include(cmake/doxytest.cmake)

# Extract tests from the header files and add build targets for the resulting test programs.
# We include the `calc.h` header file in all the test source files.
doxytest(${CMAKE_SOURCE_DIR}/include/calc INCLUDES "<calc/calc.h>" LIBRARIES calc)