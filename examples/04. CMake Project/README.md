# Sample CMake Project

This directory has some code for a sample `calc` library that is built using CMake and which uses Doxytest.

## Note

Generally, it is best practise to use _header file_ comments for doctests.
After all, the doctests are supposed to be both documentation _and_ tests!
The documentation mandate means that these code blocks need to be in the public headers.

However, some projects put major comment blocks in .cpp files for some reason.
Those projects will probably have most or their doctests in those files.

To mimic that "style", this little example has a doctest in `divide.cpp`, and to make things even more complicated, another one in the corresponding header `divide.h`.
Doxytest handles this just fine.
It will create `doxytests/doxy_divide.cpp` from the header and `doxytests/doxy_divide_cpp.cpp` from the cpp file.
