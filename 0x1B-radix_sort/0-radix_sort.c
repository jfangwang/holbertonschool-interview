#include "sort.h"


/**
 * radix_sort - Sorts in radix.
 * @array: The array to modify
 * @size: The size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int i = 0, k = 0, j = 0, max = 0, swap_index = 0, ord = 0, len = size;
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
		ord = 0;
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
			for (j = 0; j < len; j++)
			{
				for (k = ord + 1; k < len; k++)
				{
					if ((array[j] % (placement * 10)) / placement == i &&
						array[j] < array[k])
					{
						swap(array, array[j], array[ord], len);
						ord += 1;
						break;
					}
				}
			}
		}
		placement *= 10;
		print_array(array, len);
		max /= 10;
	}
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
