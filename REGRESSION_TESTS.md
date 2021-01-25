This document assumes you have already been able to build CPROVER on
your chosen architecture. For details on building CPROVER see
COMPILING.md.

Regression tests can be run using make or cmake. Your choice here
should be the same as the compiling of the project itself. (See
COMPILING.md for details of both make and cmake build processes.)

Note that running all regression tests can be slow when a non-
release build of CPROVER is used. It is highly recommended to
compile with release flags.

# MAKE

This can be done by changing to the regression directory and
simply running make as follows.
```
cd regression
make
```

# CMAKE

This can be done by changing to the directory you built the
project in with cmake and running ctest as follows.
```
cd <build_dir>
ctest . -V -L CORE
```
You can also specify a pattern of tests to run as follows.
```
ctest . -V -L CORE -R <pattern>
```
For example
```
ctest . -V -L CORE -R goto
```
that will run all CORE tests that include `goto` in their
name.

