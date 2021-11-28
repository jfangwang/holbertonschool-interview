#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heap_sort - sorts an array in heap sort order
 * @array: input list
 * @size: size of list
 * Return: Nothing, void function
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;
	int temp = 0;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, (int)size, size, i);
	for (i = (int)size - 1; i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);
		heapify(array, i, size, 0);
	}
}

/**
 * heapify - recursion of heap sorting array
 * @array: list of ints
 * @n: int, size of current subtree
 * @size: size_t, size of array
 * @i: int, index of root node
 * Return: Nothing, void function
 */
void heapify(int *array, int n, size_t size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	/* Find if left or right node is smaller */
	if (right < n && array[right] > array[largest])
		largest = right;
	if (left < n && array[left] > array[largest])
		largest = left;
	if (largest != i)
	{
		temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, n, size, largest);
	}
}
