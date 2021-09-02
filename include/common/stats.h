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


/*Functions for statistical calculation: 
* float find_mean ();
* int find_maximum ();
* int find_minimum ();
* int find_median();
*/
/**
 * @brief Basic statistical calculations on an array of SIZE = 40 elements unsigned char.
 *
 * The functions take an unsigned character pointer array and an integer of value 40, performing the calculation of:
 * -median: a float returns.
 * -median: returns an integer.
 * -maximum: returns an integer
 * -minimum: returns an integer.
 * Function to print statistical results:
 * -void print_statistics()
 *  The function takes the calculated values of the previously named ones and prints the results to the screen.
 * Functions to print the array:
 * void print_array ()
 * void sort_array ()
 * The functions take an unsigned character pointer array and an integer of value 40:
 * -print_array : Print the array.
 * -sort_array : Sort the elements contained in the array in descending order.
 * 
 */


#endif /* __STATS_H__ */
