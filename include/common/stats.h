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
 * @brief Description of the functions for the calculation.
 *
 * Description of the functions used to calculate basic statistics on an array of 40 elements.
 *
 * @author Alejandro Pereyra
 * @date 15-8-21
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Print out all the statistics related to the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * 
 * @return Void()
 */
void print_statistics(uint8_t *ptr, uint8_t length);

/**
 * @brief Prints the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * 
 * @return Void()
 */
void print_array(uint8_t *ptr, uint8_t length);

/**
 * @brief Sorts the array inplace from largest (index 0) to smallest (index n-1)
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 */
void sort_array(uint8_t *ptr, uint8_t length);

/**
 * @brief Given an array pointer and length of array, returns the minimum value in the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t minimum value in array
 */
uint8_t find_minimum(uint8_t *ptr, uint8_t length);

/**
 * @brief Given an array pointer and length of array, returns the maximum value in the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t maximum value in array
 */
uint8_t find_maximum(uint8_t *ptr, uint8_t length);

/**
 * @brief Given an array pointer and length of array, returns the average value of the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t average value in array
 */
uint8_t find_mean(uint8_t *ptr, uint8_t length);

/**
 * @brief Given an array pointer and length of array, returns the median value of the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return uint8_t median value in array
 */
uint8_t find_median(uint8_t *ptr, uint8_t length);


#endif /* __STATS_H__ */
