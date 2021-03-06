#include "sort.h"


/**
 * radix_sort - Sorts in radix.
 * @array: The array to modify
 * @size: The size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *temp, placement = 1, len = size, i, j, max = INT_MIN, ti;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		exit(EXIT_FAILURE);

	for (i = 0; i < len; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max > 0)
	{
		ti = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < len; j++)
			{
				if ((array[j] / placement) % 10 == i)
					temp[ti++] = array[j];
			}
		}
		for (i = 0; i < len; i++)
		{
			array[i] = temp[i];
		}
		print_array(array, size);
		placement *= 10;
		max /= 10;
	}
	free(temp);
}
