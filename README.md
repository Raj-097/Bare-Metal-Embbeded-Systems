# Bare-Metal Embedded Systems Coursework Project

This repository contains source code developed as part of an embedded systems course focused on low-level C programming, memory manipulation, build systems, and cross-compilation for embedded targets.

The application assignments were developed and tested on the host platform, with Makefile support for both native compilation and MSP432 cross-compilation.

## Topics Covered in Project

* Embedded C programming
* Cross-compilation for ARM Cortex-M4
* Makefile-based build automation
* Compile time switches
* Pointer manipulation
* Memory access abstractions
* Static and dynamic memory operations
* Integer/string data conversion with various base types
* Linker map file generation and analysis
* Binary utilities and analysis
* Embedded software testing and verification

## Project Components

### Part 1: Statistics utilities

A simple statistics application operating on an array of unsigned 8-bit values.

Implemented functionality includes:

* Printing of array and statistics
* Sorting in descending order
* Mean calculation
* Median calculation
* Minimum value detection
* Maximum value detection

### Part 2: Build System and Memory Abstraction

Makefile build automation of pointer-based memory abstraction functions and MSP432 platform specific files. 
Analysis using size binary utility and linker map file.

Implemented Makefile supports:

* Host compilation using GCC
* Cross-compilation for the MSP432 Cortex-M4 platform
* Dependency generation
* Preprocessed output generation
* Assembly generation
* Linker map file generation
* Automatic size utility usage upon compilation

### Part 3. Memory Analysis

As part of the coursework, linker map files and binary artifacts of given source files were analyzed using GNU Binutils tools to examine:

* Symbol locations
* Memory usage
* Section sizes
* Constant data placement
* Code and data organization

See the usage section for Makefile usage.

### Expanded and Complete Embedded Systems Project

The final project integrated the previous assignments, extended the memory abstraction library, 
implemented custom data conversion routines, and added compile time switches.

Additional memory functions implemented include:

* my_memmove() – memory movement with overlap handling
* my_memcopy() – memory copy between regions
* my_memset() – initialize memory with a specified value
* my_memzero() – clear memory to zero
* my_reverse() – reverse data at a memory location for a specified length
* reserve_words() – dynamic memory allocation wrapper
* free_words() – memory deallocation wrapper

Custom conversion functions implemented:

* my_itoa() – integer-to-string conversion for configurable bases
* my_atoi() – string-to-integer conversion for configurable bases

Compile-time feature flags were used to enable or disable functionality, including:

* VERBOSE for printing debugging and output
* COURSE1 for executing the course-1 test suite

The project includes a test framework that's used to validate implementations by peer learners. 

The build system supports both native host execution and cross-compilation for the MSP432 Cortex-M4 platform.

## Usage

For whole project, enter course1 directory and build using:

make <target> PLATFORM=<HOST|MSP432>

### Targets :
* build         Compile to generate object (.o) files and link them to build executable (.out) file
* compile-all   Compile to produce object (.o) files
* preprocess    Generate preprocessed (.i) files
* assembly      Generate assembly (.asm) files
* clean         Remove generated files

course1.c tests the implementations and reports the number of tests passed and failed.

## Toolchain

* GCC
* ARM GNU Embedded Toolchain (`arm-none-eabi-gcc`)
* GNU Make
* GNU Binutils

## Learning Outcomes

This repository demonstrates practical experience with:

* Embedded C development
* Makefile development and build automation
* Cross-platform build systems
* ARM Cortex-M4 toolchains
* Low-level memory management
* Pointer-based programming
* Linker and memory map analysis
* Analysis using GNU binary utilities
* Embedded software testing and verification
