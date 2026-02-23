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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>


/**
 * @brief Sets a value of a data array 
 *
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a pointer from src to dst, "lenght" no. of bytes
 *
 * Given two byte type pointers and a lenght of movements, the function moves from source location to destination
 *
 * @param src points to the source byte
 * @param dest points to the destination byte
 * @param length is the no. of bytes to travel 
 *
 * @return pointer to the destination.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies "lengtht" of bytes from source location to a destination
 *
 * Given two byte type pointers and a number length, the function copies lenght no. of bytes from source location to destination. If there is overlap between source and destination, function doesnt make any changes
 *
 * @param src points to the source byte
 * @param dest points to the destination byte
 * @param length is the no. of bytes to copy starting from src location to dst location 
 *
 * @return pointer to the destination.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a given no. of bytes from a given source location to a given value
 *
 * Given a byte type pointer, a length, and a value, the function sets all the bytes from the source location of the given length to the given value 
 *
 * @param src points to the source byte
 * @param length the no. of bytes to be set
 * @param value the value used to set 
 *
 * @return pointer to the source.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a given no. of bytes from a given source location to zero
 *
 * Given a byte type pointer, and a length, the function sets all the bytes from the source location of the given length to zero
 *
 * @param src points to the source byte
 * @param length the no. of bytes to be set
 *
 * @return pointer to the source.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of given no. of bytes starting from a given source location
 *
 * Given a byte type pointer, a length, and a value, the function reverses the order of the bytes starting from the given location of the given length
 *
 * @param src points to the source byte
 * @param length the no. of bytes to be reversed
 *
 * @return pointer to the source.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates dynamic memory of the given size
 *
 * Given a size, dynamic memory is allocated of the given size
 *
 * @param length the no. of bytes' space to be reserved
 *
 * @return pointer to the memory location of the starting byte allocated 
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamic memory from a given location
 *
 * Given a starting location, the dynamically  allocated memory is freed
 *
 * @param src the starting address of dynamically allocated memory
 *
 * @return void.
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
