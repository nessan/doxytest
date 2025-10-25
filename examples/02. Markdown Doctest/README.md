# README

If you run `doxytest.py` on a directory, then by default it only scans header files identified by having a `.h` or `.hpp` extension.

You can pass a `-e` or `--extensions` flag to have the script scan other types of files.
Alternatively, you can just pass files with different extensions directly as we will do here.

In this directory we have a `calc.md` file that documents the "library" in the `calc` directory.
It has several code blocks formulated as doctests.

If you do:

```sh
../../doxytest.py -f -i calc/calc.h calc.md
```

you will generate the file `doxy_calc_md.cpp` that you can compile and run

```sh
clang++ -std=c++23 doxy_calc_md.cpp
./a.out
```

This will output:

```txt
Running 3 tests extracted from: `calc.md`
test 1/3 (calc.md:9) ... pass
test 2/3 (calc.md:18) ... pass
test 3/3 (calc.md:27) ... pass
[calc.md] All 3 tests PASSED
```

## Notes

-   The name of the test file is `doxy_calc_md.cpp` because we always reserve the simplest ``doxy_calc.cpp` name for the test file extracted by scanning a _header_ file (so `calc.h` or `calc.hpp`).
-   The markdown file has a code block marked as Rust and this is completely ignored. We only process unmarked blocks or ones that are specifically marked with `cpp`.
