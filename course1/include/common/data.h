 /**
 * @file data.h
 * @brief APIs for Conversion between integer and string for various base types
 *
 * This header file provides an abstraction of conversion between
 * integer and string of given base type at function call. 
 *
 * @author Rajkumar Saravanakumar
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define BASE_16 (16)
#define BASE_10 (10) 

/**
 * @brief Converts a given integer to string based on base type given
 *
 * Given a 32 bit integer data, a pointer to a byte, and a base type, this function converts the integer value to string based on the given base and stores it in the location pointed by the pointer. Also returns the length of the string.
 *
 * @param data the input 32 bit integer value
 * @param ptr a pointer pointing a the starting location of a string
 * @param base a 32 bit integer that gives the base value
 *
 * @return length of the string 
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts a given string to integer value based on base type given
 *
 * Given a pointer to the string, no. of digits, and the base type, this function converts the string to integer value based on the base type and returns this value
 *
 * @param ptr Pointer to string
 * @param digits the no. of digits in the string
 * @param base the base value
 *
 * @return data the final integer value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
