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
 * @file stats.h 
 * @brief Header file consisting of function declarations and their descriptions which are used in stats.c
 * 
 * stats.c aims to sort a given array of unsigned bytes (unsigned char datatype) and calculate mean, median, maximimum value, and  minimum value, and to print the results
 *
 * @author Rajkumar Saravanakumar
 * @date 13/11/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(unsigned char* array, unsigned int length);
/*
 * @brief Calls other functions for calculations of statistics and prints them
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return NA
 */
void print_array(unsigned char* array, unsigned int length);
/**
 * @brief Prints the given array
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return NA
 */
unsigned char find_median(unsigned char* array, unsigned int length);
/**
 * @brief Finds the median of the given array of unsigned 8 bit numbers and returns it
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return an unsigned char type value (8 bit no.), the median
 */

unsigned char find_mean(unsigned char* array, unsigned int length);
/**
 * @brief Finds the mean of the given array of unsigned 8 bit numbers and retu
rns it
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return an unsigned char type value (8 bit no.), the mean
 */

unsigned char find_maximum(unsigned char* array, unsigned int length);
/**
 * @brief Finds the maximum no. of the given array of unsigned 8 bit numbers and retu
rns it
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return an unsigned char type value (8 bit no.), the maximum
 */
unsigned char find_minimum(unsigned char* array, unsigned int length);
/**
 * @brief Finds the minimum no. of the given array of unsigned 8 bit numbers and retu
rns it
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return an unsigned char type value (8 bit no.), the minimum
 */

void sort_array(unsigned char* array, unsigned int length);
/**
 * @brief Sorts the given array in decending order using bubble sort
 * @param array -  an unsigned char type pointer pointing to an array of unsigned char type values
 * @param length - no. of elements of the array
 * @return NA
 */



#endif /* __STATS_H__ */
