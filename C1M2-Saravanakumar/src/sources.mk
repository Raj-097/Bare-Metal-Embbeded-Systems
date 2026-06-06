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

# Source files for MSP432 target platform
MSP432_SOURCES = interrupts_msp432p401r_gcc.c \
                 main.c \
                 memory.c \
                 startup_msp432p401r_gcc.c \
                 system_msp432p401r.c

# Source files for host platform
HOST_SOURCES = main.c \
               memory.c

# Include paths for header files
INCLUDES = -I../include/CMSIS \
           -I../include/common \
           -I../include/msp432


