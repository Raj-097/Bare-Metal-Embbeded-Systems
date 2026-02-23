/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "data.h"
#include "platform.h"
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    uint8_t *start = ptr;  // Pointer to the beginning of the string
    int is_negative = 0;   // To track if the number is negative
    uint8_t length = 0;    // Length of the resulting string

    // Handle negative numbers for base 10
    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data;
    }

    // Convert the number to the specified base
    do {
        int remainder = data % base;
        *ptr++ = (remainder > 9) ? (remainder - 10 + 'A') : (remainder + '0'); // Convert to ASCII
        length++;
        data /= base;
    } while (data != 0);

    // Add the negative sign if necessary
    if (is_negative) {
        *ptr++ = '-';
        length++;
    }

    // Null terminator (making sure it's added correctly)
    *ptr = '\0';
    length++;

    // Reverse the string (since it was generated in reverse order)
    uint8_t *end = ptr - 1;
    ptr = start;
    while (ptr < end) {
        uint8_t temp = *ptr;
        *ptr++ = *end;
        *end-- = temp;
    }

    return length;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    // Check for invalid input
    if (ptr == NULL || digits == 0 || base < 2 || base > 16) {
        return 0; // Handle invalid input
    }

    bool is_negative = false;
    int32_t result = 0;
    uint8_t *current = ptr;

    // Handle optional '+' or '-' sign
    if (*current == '-') {
        is_negative = true;
        current++;
        digits--;
    } else if (*current == '+') {
        current++;
        digits--;
    }

    // Convert ASCII characters to integer based on the base
    for (uint8_t i = 0; i < digits; i++, current++) {
        if (*current == '\0') {  // Stop if null character is encountered
            break;
        }

        int8_t value;

        // Handle digits 0-9
        if (*current >= '0' && *current <= '9') {
            value = *current - '0';
        }
        // Handle letters A-F (uppercase and lowercase) for hexadecimal
        else if (*current >= 'A' && *current <= 'F') {
            value = *current - 'A' + 10;
        }
        else if (*current >= 'a' && *current <= 'f') {
            value = *current - 'a' + 10;
        } else {
            return 0; // Invalid character for the base
        }

        if (value >= base) {
            return 0; // Invalid digit for the base
        }

        // Accumulate result
        result = result * base + value;
    }

    return is_negative ? -result : result;
}

