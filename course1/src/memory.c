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
 * @file memory.c
 * @brief Expanded abstraction of memory read and write operations
 *
 * This implementation file provides an expanded abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Alex Fosdick
 * @author Rajkumar Saravanakumar
 */

#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char *ptr, unsigned int index, char value)
{
    ptr[index] = value;
}

void clear_value(char *ptr, unsigned int index)
{
    set_value(ptr, index, 0);
}

char get_value(char *ptr, unsigned int index)
{
    return ptr[index];
}

void set_all(char *ptr, char value, unsigned int size)
{
    unsigned int i;
    for (i = 0; i < size; i++)
    {
        set_value(ptr, i, value);
    }
}

void clear_all(char *ptr, unsigned int size)
{
    set_all(ptr, 0, size);
}

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
    if (src == NULL || dst == NULL)
    {
        return NULL;
    }

    /* If source and destination overlap, copy backwards
     * to avoid overwriting source data before it is copied.
     */
    if (src < dst && src + length > dst)
    {
        // Move pointers to the end of the memory regions
        src += length - 1;
        dst += length - 1;

        while (length--)
        {
            *dst = *src;
            dst--;
            src--;
        }
    }
    else
    {
        // No overlap (or safe overlap), copy forwards
        while (length--)
        {
            *dst = *src;
            dst++;
            src++;
        }
    }

    return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length)
{
    if (src == NULL || dst == NULL)
    {
        return NULL;
    }

    // Copy bytes sequentially from source to destination
    while (length--)
    {
        *dst = *src;
        dst++;
        src++;
    }

    return dst;
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value)
{
    if (src == NULL)
    {
        return NULL;
    }

    // Set each byte in the memory region to the specified value
    while (length--)
    {
        *src = value;
        src++;
    }

    return src;
}

uint8_t *my_memzero(uint8_t *src, size_t length) 
{
    if (src == NULL)
    {
        return NULL;
    }

    uint8_t *ptr = src;

    // Set all bytes in the memory region to zero
    while (length--)
    {
        *ptr = 0;
        ptr++;
    }

    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) 
{
    if (src == NULL || length == 0)
    {
        return src;
    }

    uint8_t * start = src;
    uint8_t * end = src + length - 1;

    // Swap bytes from both ends until the middle is reached
    while (start < end)
    {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }

    return src;
}

int32_t *reserve_words(size_t length)
{
    // Allocate memory for the requested number of 32-bit words
    return (int32_t *)malloc(length * sizeof(int32_t));
}

void free_words(int32_t *src)
{
    // Free previously allocated memory
    free(src);
}