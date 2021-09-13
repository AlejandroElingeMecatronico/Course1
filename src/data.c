/******************************************************************************
 * Copyright (C) 2021 by AleElIngeMecatronico
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 *
 ******************************************************************************
 *
 * @file data.c 
 * @brief This file is the data file for the final assessment of course1.
 * @author AlejandroElingeMecatronico
 * @date 12-09-21
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  //unsigned int i = 0;
  bool negative = false;
  int32_t num = data;
  uint8_t  tem_array[12];
  unsigned int rem=0;
  uint32_t cont_digits=0;
  if(num == 0)
  {
    *(ptr + cont_digits) = 0;
    *(ptr + cont_digits+1) ='\0';
    return 2;
  }
  if (num < 0)
  {
    negative = true;
    num = -num;
  }

  while(num != 0)
  {
    rem = num % base;
    if(rem <= 9 && rem>=0){tem_array[cont_digits] = rem + 0x30;}
    if(rem>9 && rem<=15){tem_array[cont_digits]=rem + 0x37;}
    cont_digits++;
    num = num/base;
  }
  if(negative){cont_digits++;tem_array[cont_digits]='-';}
  //reverse 
  for(int i=0 ; i<cont_digits; i++)
  {
    *(ptr+i) = tem_array[cont_digits-1-i];
  }
  cont_digits++;
  *(ptr+cont_digits)='\0';
  return cont_digits;
    
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  uint8_t * num = ptr;
  uint32_t number=0;
  unsigned int i=0;
  uint8_t digit = 0;
  printf("la cantidad de digitos es: %d.\n",digits);
  if(*(num+i) == '-')
  {
    for(i=1;*(num+i)!='\0';i++)
    {
      uint32_t multiplier = pow(base,(digits-2-i));
      if(*(num+i)>=48 && *(num+i)<=57)
      {
      digit = *(num + i) - 48;
      number = number + digit * multiplier;
      }
      if(*(num+i)>=60 && *(num+i)<=70)
      {
      digit = *(num + i) - 55;
      number = number + digit * multiplier;
        } 
      }
     number = number * -1; 
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
  else {
    for(i=0 ; *(num+i)!='\0' ; i++)
    {
      uint32_t multiplier = pow(base,(digits-2-i));
      //printf("%d.\n",*(num+i));
      if(*(num+i)>=48 && *(num+i)<=57)
      {
      digit = *(num + i) - 48;
      number = number + digit * multiplier;
      }
      if(*(num+i)>=60 && *(num+i)<=70)
      {
      digit = *(num + i) - 55;
      number = number + digit * multiplier;
      }
    }
  }
  return number;
}