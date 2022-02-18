#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    // int array[] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 58, 88, 38, 55, 45, 67, 88, 1, 111, 88, 32, 56, 86, 65, 21, 11, 69, 47, 35};
    
    int array[] = {170};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
