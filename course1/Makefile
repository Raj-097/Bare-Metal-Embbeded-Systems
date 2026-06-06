#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# @file    Makefile
# @brief   Portable build system for HOST and MSP432 platforms.
#
# Supports object generation, preprocessing, assembly generation,
# dependency generation, executable creation, map file generation,
# and code size reporting for Host and MSP432 target platforms.
#
# Provides configuration needed for course 1 final assessment 
# through preprocessor flags.
#
# @author  Rajkumar Saravanakumar
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Makefile to compile C files at host and MSP432 platforms
# 
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build        - Build executable and display size information using size
#      compile-all  - Compile source files into object files without linking
#      preprocess   - Generate preprocessed source files (.i)
#      assembly     - Generate assembly files (.asm)
#      clean        - Remove generated files
#
# Platform Overrides:
#      HOST         - Build for host machine using GCC
#      MSP432       - Cross-compile using arm-none-eabi-gcc
#
#------------------------------------------------------------------------------

include sources.mk

# Default platform
PLATFORM ?= HOST

# Common compiler flags
CFLAGS = -Wall \
         -g \
         -O0 \
         -std=c99

# Preprocessor flags

# Include directories
CPPFLAGS = $(INCLUDES)

# Define target platform macro
CPPFLAGS += -D$(PLATFORM)

# Enable printing
CPPFLAGS += -DVERBOSE    # Comment out to disable verbose output

# Enable Course 1 deliverable
CPPFLAGS += -DCOURSE1  

# Architecture specific flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = mthumb
SPECS = --specs=nosys.specs

# Object files
MSP432_OBJS = $(MSP432_SOURCES:.c=.o)
HOST_OBJS = $(HOST_SOURCES:.c=.o)

# Preprocessed files
MSP432_PPFILES = $(MSP432_SOURCES:.c=.i)
HOST_PPFILES = $(HOST_SOURCES:.c=.i)

# Assembly Files
MSP432_ASMFILES = $(MSP432_SOURCES:.c=.asm)
HOST_ASMFILES = $(HOST_SOURCES:.c=.asm)

# Platform selection
ifeq ($(PLATFORM), MSP432)
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    CFLAGS += -mcpu=$(CPU) -$(ARCH) -march=armv7e-m -mfpu=fpv4-sp-d16
    OBJS = $(MSP432_OBJS)
    PPFILES = $(MSP432_PPFILES)
    ASMFILES = $(MSP432_ASMFILES)
    LDFLAGS = -T../$(LINKER_FILE) -Xlinker -Map=c1m4.map $(SPECS) 
    SIZE_TOOL = arm-none-eabi-size
    
else ifeq ($(PLATFORM), HOST)
    CC = gcc
    LD = gcc
    LDFLAGS = -lm -Xlinker -Map=c1m4.map  
    OBJS = $(HOST_OBJS)
    PPFILES = $(HOST_PPFILES)
    ASMFILES = $(HOST_ASMFILES)
    SIZE_TOOL = size
endif

# Makefile target names
.PHONY: build compile-all preprocess assembly clean

# Build: link object files into an executable and run size tool
build: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o c1m4.out
	$(SIZE_TOOL) c1m4.out

# Preprocess: Generate preprocessed files (.i)
preprocess: $(PPFILES)

# Assembly: Generate assembly files (.asm)
assembly: $(ASMFILES)

# Compile source files into object files (.o) without linking
compile-all: $(OBJS)

# Generate .i files (preprocessed output)
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -E $< -o $@

# Generate .asm files (assembly output)
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@
    
# Generating object files
src/interrupts_msp432p401r_gcc.o: src/interrupts_msp432p401r_gcc.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -mgeneral-regs-only -c $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

	# Generate dependency files
	$(CC) -MM $(CPPFLAGS) $(CFLAGS) $< > $*.d

# Clean: Remove all generated files
clean:
	rm -f src/*.o src/*.i src/*.asm src/*.d *.map *.out c1m4.out

# Including the dependency files in the makefile
-include $(OBJS:.o=.d)
