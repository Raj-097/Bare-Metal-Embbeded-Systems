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
# @file    sources.mk
# @brief   Source files and include directories used by the build system.
#
# @author  Rajkumar Saravanakumar
#------------------------------------------------------------------------------

# Source files in the project
MSP432_SOURCES = src/interrupts_msp432p401r_gcc.c \
                 src/main.c \
                 src/memory.c \
                 src/startup_msp432p401r_gcc.c \
                 src/system_msp432p401r.c \
	             src/data.c \
	             src/course1.c \
	             src/stats.c

HOST_SOURCES = src/stats.c \
               src/data.c \
               src/memory.c \
               src/course1.c \
               src/main.c

# Include paths for header files
INCLUDES = -Iinclude/CMSIS \
           -Iinclude/common \
           -Iinclude/msp432


