#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#
#
#
#@author AlejandroElingeMecatronico
#@date 12-09-21
#------------------------------------------------------------------------------
include sources.mk

SHELL=/bin/bash

PLATFORM=HOST
VERBOSE=VERBOSE
COURSE1=COURSE1

#FLAGS_BOTH 
CFLAGS_BOTH= -g \
				-std=c99 \
				-O0 \
				-Wall \
				#-Werror
#TARGET FOT BOTH
TARGET = final_assessment

# Platform ARM
ifeq ($(PLATFORM),MSP432)
	#ARCHITECTURE and SPECIFICS FLAGS ARM
	LINKER_FILE = ./msp432p401r.lds
	CPU = cortex-m4
	ARCH_FLAGS = -mthumb\
	             -march=armv7e-m\
	             -mfloat-abi=hard\
	             -mfpu=fpv4-sp-d16\
	             --specs=nosys.specs
	
	CFLAGS_ARCH = -mcpu=$(CPU) $(ARCH_FLAGS) 
	CFLAGS = $(CFLAGS_BOTH) $(ARCH_FLAGS)
	LDFLAGS_ARCH = -T $(LINKER_FILE)
	LDFLAGS = -Wl,-Map=$(TARGET).map $(LDFLAGS_ARCH) -lm
	CPPFLAGS = -DMSP432 $(INCLUDES)

	#COMPILERFLAGS AND DEFINES ARM
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	SOURCES += 	./src/startup_msp432p401r_gcc.c\
				./src/system_msp432p401r.c\
				./src/interrupts_msp432p401r_gcc.c			
endif

ifeq ($(PLATFORM),HOST)
	#FLAGS , COMPILER FLAGS TO HOST
	CC = gcc
	CFLAGS = $(CFLAGS_BOTH)
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map -lm
	SIZE = size
endif

ifeq ($(COURSE1),COURSE1)
	CPPFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE),VERBOSE)
	CPPFLAGS += -DVERBOSE
endif		


OBJS = $(SOURCES:.c=.o) #objects files
ASM = $(SOURCES:.c=.asm) #assembler files
PRE_P = $(SOURCES:.c=.i) #preprocesor files
DEP = $(SOURCES:.c=.d) #dependency files


.PHONY : build
build : $(TARGET).out

$(TARGET).out : $(OBJS)	
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm : %.c 
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o : %.c 
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d : %.c
	$(CC) -E -M $< $(CFLAGS) -o $@


.PHONY : compile-all
compile-all: $(OBJS)

.PHONY:clean
clean :
	@echo Removing all built files
	rm -f ./src/*{.o,.out,.map,.asm,.i} $(TARGET).out
	


