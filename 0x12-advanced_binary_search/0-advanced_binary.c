#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_list - Prints a list of numbers from left to right
 * @array: input list
 * @left: index of left
 * @right: index of right
 * Return: Nothing, void function
 */
void print_list(int *array, int left, int right)
{
	if (left == right)
	{
		printf(" %d\n", array[right]);
		return;
	}
	printf(" %d,", array[left]);
	print_list(array, left + 1, right);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: input list
 * @size: size of list
 * @value: target number to look for in list
 * Return: -1 if value is not found, otherwise return index of value.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	if (size == 1)
	{
		if (array[0] == value)
			return (0);
		return (-1);
	}

	return (recurse(array, 0, size - 1, value));
}

/**
 * recurse - binary search with recursion
 * @array: input list
 * @left: index of left
 * @right: index of right
 * Return: Nothing, void function
 */

int recurse(int *array, int left, int right, int value)
{
	int mid = left + ((right - left) / 2);

	if (left <= right)
	{
		printf("Searching in array:");
		print_list(array, left, right);
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			return (recurse(array, left, mid, value));
		return (recurse(array, mid + 1, right, value));
	}
	return (-1);
}
