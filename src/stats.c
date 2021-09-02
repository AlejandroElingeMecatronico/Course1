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
 * @brief calculation of basic statistics in c language.
 *
 * Program that shows the simple calculation of some basic statistical parameters of an n-dimensional array:
 * -Median
 * -Mean
 * -Maximum
 * -Minimum
 * 
 * In addition to printing on screen the arrangement, the calculated values and the arrangement in descending order.
 *
 * @author Alejandro Pereyra
 * @date 15-8-21
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*function prototypes*/
void print_array (unsigned char *ptr , int n);
void print_statistics(float a,int b ,int c ,int d);
float find_mean (unsigned char *ptr , int n);
int find_maximum (unsigned char *ptr , int n);
int find_minimum (unsigned char *ptr , int n);
void sort_array (unsigned char *ptr , int n);
int find_median(unsigned char *ptr , int n);
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  float mean;
  int maximum,minimum,median;                             
  /* Statistics and Printing Functions Go Here */
  printf("unordered array-[Position]/Value: ");
  print_array(test, SIZE);
  mean = find_mean(test , SIZE);                              
  maximum = find_maximum(test , SIZE);
  minimum = find_minimum(test , SIZE);
  sort_array(test , SIZE);
  printf("descending ordered array-[Position]/Value: ");
  print_array(test, SIZE);
  median = find_median(test , SIZE);
  print_statistics(mean,maximum,minimum,median); 
}
/* Add other Implementation File Code Here */
void print_array (unsigned char *ptr , int n){
     printf("\n"); 
     int i;
     for (i=0 ; i<n ; i++){
      if(i==39){
        printf("[%d]/%d.",i+1,*(ptr+i));
      }
      else {
        printf("[%d]/%d, ",i+1,*(ptr+i));
      }
     }
     printf("\n");
}

void print_statistics(float a,int b ,int c, int d){
      printf("mean = %.0f \n", a);
      printf("maximum = %d.\n",b);
      printf("minimum = %d.\n",c);
      printf("median = %d.\n",d);
}

float find_mean(unsigned char *ptr , int n){
    int i;
    float sum=0.0;
    for(i=0;i<n;i++){
      sum = sum + *(ptr+i);
    } 
    return sum/n;
}

int find_maximum (unsigned char *ptr , int n){
  int i;
  int a , b;
  for(i=0;i<n;i++){
   b = *(ptr+i); 
      if(b>a){
        a = b;
      }
    }  
  return a;    
}

int find_minimum (unsigned char *ptr , int n){
  int i;
  int a,b;
  for(i=0;i<n;i++){
   b = *(ptr+i); 
      if(b<a){
        a = b;
      }
    }  
  return a;    
}

void sort_array (unsigned char *ptr , int n){
  int i , j , aux;

  for (i=0 ; i<n ; i++){
    for (j=0 ; j<n ; j++){
      if(*(ptr+j) < *(ptr+j+1)){
        aux = *(ptr+j+1);
        *(ptr+j+1)= *(ptr+j);
        *(ptr+j)=aux; 
      }
    }
  }
}

int find_median(unsigned char *ptr , int n){
  int pos = n / 2 ; 
  int median = *(ptr+pos-1) + *(ptr+pos);
  median = median / 2 ;
  return median;
}