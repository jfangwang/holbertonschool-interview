#include "sort.h"


/**
 * radix_sort - Sorts in radix.
 * @array: The array to modify
 * @size: The size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int i = 0, j = 0, max = 0, swap_index = 0, len = size;
	int placement = 1;

	if (size == 0)
		return;
	while (i < len)
	{
		if (array[i] > max)
			max = array[i];
		i += 1;
	}
	while (max > 0)
	{
		swap_index = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < len; j++)
			{
				if ((array[j] % (placement * 10)) / placement == i)
				{
					swap(array, array[j], array[swap_index], len);
					swap_index = swap_index + 1;
				}
			}
		}
		_sort(array, len, placement);
		placement *= 10;
		print_array(array, len);
		max /= 10;
	}
}


/**
 * Sort the array
 * @array: The array to modify
 * @size: size of arr
 * @placement: digit place
 * Return: Array
 */
int *_sort(int *array, int size, int placement)
{
	int min = -1, a,b, digit;

	digit = (array[0] % (placement * 10)) / placement;
	for (a = 0; a < size; a++)
	{
		if (((array[a] % (placement * 10)) / placement) != digit)
			digit = (array[a] % (placement * 10)) / placement;
		min = array[a];
		for (b = a; b < size; b++)
		{
			if (min > array[b] && (array[b] % (placement * 10)) / placement == digit)
			{
				min = array[b];
			}
		}
		swap(array, array[a], min, size);
	}
	return (array);
}


/**
 * swap - swaps 2 nums in arr.
 * @array: The array to modify
 * @num1: int
 * @num2: int
 * @size: size of arr
 * Return: Array
 */
int *swap(int *array, int num1, int num2, int size)
{
	int i = 0;

	while (i < size)
	{
		if (array[i] == num1)
		{
			array[i] = num2;
			i += 1;
			continue;
		}
		if (array[i] == num2)
		array[i] = num1;
		i += 1;
	}
	return (array);
}
