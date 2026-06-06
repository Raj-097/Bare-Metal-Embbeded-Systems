# Portable Build System with Make

## Author

Rajkumar Saravanakumar

## Overview

This project develops a portable Makefile-based build system for both HOST and MSP432 platforms. The build system supports compilation, linking, preprocessing, assembly generation, dependency generation, executable size analysis using the size utility, and memory layout analysis through generated map files.

## Usage

make <target> PLATFORM=<HOST|MSP432>

## Targets

* build - Compile source files, link object files, generate an executable, and display size information.
* compile-all - Compile source files into object files without linking.
* preprocess - Generate preprocessed source files (.i).
* assembly - Generate assembly files (.asm).
* clean - Remove generated files.