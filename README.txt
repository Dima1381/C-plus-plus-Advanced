README
======

The program:
Demonstrates working with memory allocation and deallocation in the heap.
This program generates a large number of arrays with random numbers,
calculates the median of each array, checks if the median is divisible by 13,
and returns the count of such medians.
To achieve this, it dynamically allocates memory for each array, sorts it to calculate the median,
and releases the memory after the work is done.
The main functionality is implemented in the file <MemoryManager.c> in the function <get_running_count()>.


This package includes the following files.

|-- Driver.c [This is the driver program which will be used to invoke the MemoryManager.]
|-- MemoryManager.c [MemoryManager is implemented here.]
|-- MemoryManager.h [Header file declaring the function exposed from MemoryManager]
|-- README.txt [This file]


To compile:
    make all

To run:
    ./Driver <seed>

For example;
    ./Driver 1234


Information about the work I have done:

I worked only in the method "get_running_count()". 
Without changing any files and other methods. 
Create a makefile and rewrote README.txt

Interesting thing:
To get the same result as in "Homework_1_Instruction", 
we need to reproduce the same number of rand() calls.

