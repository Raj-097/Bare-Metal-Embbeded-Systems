# Memory Manipulation, Data Conversion, and Statistics Utilities with Compile-Time Switches

## Author

Rajkumar Saravanakumar

## Overview

This project implements memory manipulation, data conversion, and statistical analysis utilities 
for both HOST and MSP432 platforms. Features include custom implementations of memory operations 
(memmove, memcopy, memset, memzero, reverse), dynamic memory allocation and deallocation wrappers, 
integer/string conversion utilities, and statistical calculations such as mean, median, maximum, and minimum. 

The build system supports platform selection and configurable functionality including 
enable / disable printing and course-1 testing through compile-time switches.

## Usage

make <target> PLATFORM=<HOST|MSP432>

### Targets

* build - Compile source files, link object files, generate an executable, and display size information.
* compile-all - Compile source files into object files without linking.
* preprocess - Generate preprocessed source files (.i).
* assembly - Generate assembly files (.asm).
* clean - Remove generated files.

### Compile-Time Switches

Added in the Makefile.

* -DCOURSE1 - Enable Course 1 test suite.
* -DVERBOSE - Enable detailed program output.