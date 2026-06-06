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
 * @file stats.c 
 * @brief Statistics calculations and sorting of an array of 8 bit numbers
 *
 * The main function gets the unsorted array of unsigned char type numbers  
 * as its paramter, which calls different functions for sorting of the array,  
 * calculations of mean, median, maximum value, and minimum value, and for 
 * printing the results.
 *
 * @author Rajkumar Saravanakumar
 * 
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

   unsigned int length = SIZE;

   printf("Original Array:\n");
   print_array(test, length);

   // Sorting the array
   sort_array(test, length);

   printf("Sorted Array (Largest to Smallest):\n");
   print_array(test, length);

   // Print statistics
   print_statistics(test, length);
}

void print_statistics(unsigned char* array, unsigned int length) {
    printf("\nArray Statistics:\n");
    printf("Minimum: %u\n", find_minimum(array, length));
    printf("Maximum: %u\n", find_maximum(array, length));
    printf("Mean: %u\n", find_mean(array, length));
    printf("Median: %u\n", find_median(array, length));
}

void print_array(unsigned char* array, unsigned int length) {
    // Traverse and print with spacing
    for (unsigned int i = 0; i < length; i++) {
        printf("%u ", array[i]);
    }

    printf("\n");  // print new line
}

unsigned char find_median(unsigned char* array, unsigned int length) {
    // Even number of elements -> return average of center values
    if (length % 2 == 0) {
        return (array[length / 2 - 1] + array[length / 2]) / 2;
    } 
    else {
        return array[length / 2];
    }
}

unsigned char find_mean(unsigned char* array, unsigned int length) {
    unsigned int sum = 0;

    // Compute sum and divide by total number of elements
    for (unsigned int i = 0; i < length; i++) {
        sum += array[i];
    }

    return sum / length;
}

unsigned char find_maximum(unsigned char* array, unsigned int length) {
    unsigned char max = array[0];

    // Traverse the array and store minimum value in variable max
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

unsigned char find_minimum(unsigned char* array, unsigned int length) {
    unsigned char min = array[0];

    // Traverse the array and store minimum value in variable min
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

void sort_array(unsigned char* array, unsigned int length) {
    // Bubble sort to sort in descendig order
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                unsigned char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

