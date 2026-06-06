/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains imlementatins of functions of integer to string and
 * string to integer conversion according to given base type
 *
 * @author Rajkumar Saravanakumar
 */

#include "data.h"
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    uint8_t *start = ptr; // Pointer to the beginning of the string
    int is_negative = 0;  // To track if the number is negative
    uint8_t length = 0;   // Length of the resulting string
    uint32_t udata;
    // Handle negative numbers for base 10
    if (data < 0 && base == 10)
    {
        is_negative = 1;
        data = -data;
        udata = data;
    }
    else
        udata = (uint32_t)data;

    // Convert the number to the specified base
    do
    {
        int remainder = udata % base;
        *ptr++ = (remainder > 9) ? (remainder - 10 + 'A') : (remainder + '0'); // Convert to ASCII
        length++;
        udata /= base;
    } while (udata != 0);

    // Add the negative sign if necessary
    if (is_negative)
    {
        *ptr++ = '-';
        length++;
    }

    // Null terminator (making sure it's added correctly)
    *ptr = '\0';
    length++;

    // Reverse the string (since it was generated in reverse order)
    uint8_t *end = ptr - 1;
    ptr = start;
    while (ptr < end)
    {
        uint8_t temp = *ptr;
        *ptr++ = *end;
        *end-- = temp;
    }

    return length;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    // Check for invalid input
    if (ptr == NULL || digits == 0 || base < 2 || base > 16)
    {
        return 0; // Handle invalid input
    }

    bool is_negative = false;
    uint32_t result = 0;
    uint8_t *current = ptr;

    // Handle optional '+' or '-' sign
    if (*current == '-')
    {
        is_negative = true;
        current++;
        digits--;
    }
    else if (*current == '+')
    {
        current++;
        digits--;
    }

    // Convert ASCII characters to integer based on the base
    for (uint8_t i = 0; i < digits; i++, current++)
    {
        if (*current == '\0')
        { // Stop if null character is encountered
            break;
        }

        int8_t value;

        // Handle digits 0-9
        if (*current >= '0' && *current <= '9')
        {
            value = *current - '0';
        }
        // Handle letters A-F (uppercase and lowercase) for hexadecimal
        else if (*current >= 'A' && *current <= 'F')
        {
            value = *current - 'A' + 10;
        }
        else if (*current >= 'a' && *current <= 'f')
        {
            value = *current - 'a' + 10;
        }
        else
        {
            return 0; // Invalid character for the base
        }

        if (value >= base)
        {
            return 0; // Invalid digit for the base
        }

        // Accumulate result
        result = result * base + value;
    }
    
    int32_t res = (int32_t)result;
    return is_negative ? -res : res;
}
