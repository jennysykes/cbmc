## Overview of CProver Tools

This document provides a brief overview of the various tools in
CProver project. The goal is as to provide a lightweight reference
with links to detailed documentation on each of the tools.

The tools in the CProver project are as follows:
- [cbmc](#cbmc)
- [goto-analyzer](#goto-analyzer)
- [goto-cc (goto-gcc, goto-ld)](#goto-cc)
- [goto-diff](#goto-diff)
- [goto-harness](#goto-harness)
- [goto-instrument](#goto-instrument)
- [janalyzer](#janalyzer)
- [java-unit](#java-unit)
- [jbmc](#jbmc)
- [jdiff](#jdiff)
- [memory-analyzer](#memory-analyzer)
- [smt2_solver](#smt2_solver)
- [symtab2gb](#symtab2gb)
- [unit](#unit)
- [others (converter, driver, file_converter, java-converter)](#others)

The rest of this document provides a section on each of these tools in alphabetical order.
Most links to documentation here are to the CProver online documentation that can be
[here](http://cprover.diffblue.com/index.html).


## cbmc

The C Bounded Model Checker (`cbmc`) is the main tool used in the CProver suite.
`cbmc` does the entire analysis from the source code through to the result,
including generating traces. This includes invoking various sub-tools and 
modules.

For details on usage of the `cbmc` tool see the following documentation
- [Developer Tutorial](http://cprover.diffblue.com/tutorial.html)
includes a very brief tutorial on many aspects of `cbmc` and other tools.

For details on the architecture of the `cbmc` tool and how the analysis is performed
see the following documents:
- [CBMC Architecture](http://cprover.diffblue.com/cbmc-architecture.html)
gives a high level overview of the `cbmc` architecture and data flow.
- [Background Concepts](http://cprover.diffblue.com/background-concepts.html)
overviews all the key concepts used in the `cbmc` analysis.

For details on compiling, testing, contributing, and documentation related to 
development see:
- [CProver Development Documentation](http://cprover.diffblue.com/index.html)


## goto-analyzer

This provides a way to access and invoke various forms of analysis on
C source files.

Documentation useful for this tool can be found:
- [Analysis Information](http://cprover.diffblue.com/group__analyses.html)

Details of all the options can be seen by running
```
goto-analyzer --help
```

## goto-cc

This is a a compiler that also adds goto program information to the compiled
programs. Note that `goto-cc` is the compiler and linker and `goto-gcc` and
`goto-ld` are symbolic links to `goto-cc`. The additional object code is
used as the internal representation for cbmc and related tools. These can
also be extracted and used themselves (see .... below).

Further information on `goto-cc` can be found:
- [Developer Tutorial](http://cprover.diffblue.com/tutorial.html) with
some very simple examples and notes.
- [goto-cc](http://cprover.diffblue.com/group__goto-cc.html) information
on the `goto-cc` compilers
- [goto Programs](http://cprover.diffblue.com/group__goto-programs.html)
for information on goto programs and how they are used.


## goto-diff

Provides a variety of difference checks between two goto programs (produced
by `goto-cc`). This invokes some of the cbmc tools to convert the goto
program and then determine which functions are added/removed/changed.

Details of all the options can be seen by running
```
goto-diff --help
```
this includes both options for the difference, and options for the goto
program instrumentation.


## goto-harness

This is tool for creating a harness around a (part of a) goto program that
can then be analysed inside the harness. Harnesses can be either function
call environments, or memory snapshots. 

Documentation on `goto-harness` can be found
[here](http://cprover.diffblue.com/md__home_travis_build_diffblue_cbmc_doc_architectural_goto-harness.html)
including details and examples.

Details of all the options can be seen by running
```
goto-harness --help
```


## goto-instrument

This is a collection of tools for analysing and modifying goto programs 
(programs created with #goto-cc). Generally these take a goto program 
and output another goto program.

Further examples and documentation can be found:
- [goto Instrument](http://cprover.diffblue.com/group__goto-instrument.html)
has an overview of `goto-instrument` and a small tutorial example.
- [Developer Tutorial](http://cprover.diffblue.com/tutorial.html) has high
level overview and some example commands for `goto-instrument`.


## janalyzer

This provides a way to access and invoke various forms of analysis on
Java programs.

Documentation useful for this tool can be found:
- [Analysis Information](http://cprover.diffblue.com/group__analyses.html)

Details of all the options can be seen by running
```
janalyzer --help
```

## java-unit

Runs Java unit tests. For more details use
```
java-unit --help
```
Default behaviour is to only show failed test cases.


## jbmc

This is the main analysis engine the performs the analysis
of Java files using bounded model checking. This is a
Java version of the `cbmc` tool (more documentation for
`cbmc` is available and much of it applies to `jbmc`
since they use many of the same back end utilities).

For a some light information on usage of the jbmc tool see the following documentation
- [JBMC homepage](https://www.cprover.org/jbmc/) includes some
simple examples and information.

For details on how analysis is performed in the `cbmc` and
`jbmc` tools see see the following documents:
- [CBMC Architecture](http://cprover.diffblue.com/cbmc-architecture.html)
gives a high level overview of the `cbmc` architecture and data flow that *should also apply to* `jbmc`.
- [Background Concepts](http://cprover.diffblue.com/background-concepts.html)
overviews all the key concepts used in the `jbmc` analysis.

For details on compiling, testing, contributing, and documentation related to development see:
- [CProver Development Documentation](http://cprover.diffblue.com/index.html)


## jdiff

Provides a variety of difference checks between two goto programs (produced
by `goto-cc`). This invokes some of the `cbmc` tools to convert the goto
program and then determine which functions are added/removed/changed.

Details of all the options can be seen by running
```
jdiff --help
```
this includes both options for the difference, and options for the goto
program instrumentation.


## memory-analyzer

This is a wrapper program that provides a front end to `gdb` that adds some
useful features related to the other goto utilities. Note that to used
`memopry-analyzer` the program must be compiled with `goto-cc`. To make
best use of `memory-analyzer` and `gdb` you should compile with the `-g`
option. The `memory-analyzer` can also be used to create harsnesses for use
with `goto-harness`.

For further documentation and examples see 
[here](http://cprover.diffblue.com/md__home_travis_build_diffblue_cbmc_doc_architectural_memory-analyzer.html).


## smt2_solver

This is an (Satisfiability Modulo Theory) SMT solver that is shipped
with CProver. The SMT solver here is built on top of a Satisfiability
(SAT) solver. The `smt2_solver` is designer to work with files, and
so can be called with a file argument.

Details on the general use of solvers in CProver and some related
information can be found [here](http://cprover.diffblue.com/group__solvers.html).

## symtab2gb

This utility is to compile a cbmc symbols table (in JSON format) into a goto binary.
For usage run
```
symtab2gb --help
```


## unit

Runs C unit tests. For more details use
```
unit --help
```
Default behaviour is to only show failed test cases.


## others

These (`converter`, `driver`, `file_converter`, `java-converter`)
are build time utilities for other tools and not designed
to be run independently.