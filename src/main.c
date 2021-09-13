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
 *@file main.c 
 * @brief This file is the main file for the final assessment of course1.
 * @author AlejandroElingeMecatronico
 * @date 12-09-21
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"
#include "stats.h"
#include "data.h"
#include "course1.h"

int main(){
    #ifdef COURSE1
        course1();
        return 0;  
    #endif

    return 0;
}


