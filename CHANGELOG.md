# CHANGELOG

We will document notable changes in this file.

## v1.0.0

Initial release.

## 2.0.0

The initial release only scanned C++ header files for embedded doctests in comments where all the lines were prefixed by `///`.
This version looks for doctests in any passed file and can handle doctests with any well known comment prefix.
This means it can now handle doctests in Javadoc style comment blocks, as well as no-prefix comments in Markdown files, etc.

## 2.1.0

Changed the order of the included headers in the generated test files.
The standard library ones come first, the any user requested ones next, and finally the header file that generated the tests.
This allows the user requested headers to override any standard library definitions if needed.
