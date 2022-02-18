#include "sort.h"


/**
 * radix_sort - Sorts in radix.
 * @array: The array to modify
 * @size: The size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
    int i = 0;
    int j = 0;
    int max = 0;
    int swap_index = 0;
    int len = size;
    int placement = 1;


    if (size == 0)
        return;
    while (i < len) {
        if (array[i] > max)
            max = array[i];
        i = i + 1;
    }
    swap_index = 0;
    while(max > 0) {
        swap_index = 0;
        for(i=0; i<10; i++) {
            for(j=0; j<len; j++) {
                if ((array[j] % (placement * 10)) / placement == i) {
                    printf("%d\n", (array[j] % (placement * 10)));
                    swap(array, array[j], array[swap_index], len);
                    swap_index = swap_index + 1;
                }
            }
        }
        placement += 1;
        print_array(array, len);
        max = max / 10;
    }
}


int *swap(int *array, int num1, int num2, int size)
{
    int i = 0;

    while (i < size) {
        if (array[i] == num1) {
            array[i] = num2;
            i = i + 1;
            continue;
        }
        if (array[i] == num2) {
            array[i] = num1;
        }
        i = i + 1;
    }
    return (array);

}