#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int *swap(int *array, int num1, int num2, int size);


#endif
