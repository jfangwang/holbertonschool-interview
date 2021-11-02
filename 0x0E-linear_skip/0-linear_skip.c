#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - a function that searches for a
 * value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in, assume the list
 * is sorted in ascending order.
 * @value: Int value to search for.
 * Return: If value is not present in list or if head is NULL,
 * your function must return NULL. Every time you compare a value in the list
 * to the value you are searching, you have to print this value.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *scout;

	if (!list)
		return (NULL);

	while (list->express && list->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		list->express->index, list->express->n);
		list = list->express;
	}

	if (list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		list->express->index, list->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		list->index, list->express->index);
	} else
	{
		scout = list;
		while (scout->next)
			scout = scout->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		list->index, scout->index);
	}

	while (list->n != value && list->next != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	if (list->next == NULL)
		return (NULL);
	return (list);
}
