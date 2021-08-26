#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Check if single linked list is a palindrome
 * @head: head of the list
 * Return: 0 or 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *node;
	int len = 1;
	int *arr;
	int idx = 0;

	if (head == NULL)
		return (1);
	node = malloc(sizeof(listint_t));
	node = *head;


	while (node->next != NULL)
	{
		node = node->next;
		len++;
	}
	node = *head;

	arr = malloc(len * 4);

	len--;
	idx = len;
	while (idx >= 0)
	{
		arr[idx] = node->n;
		node = node->next;
		idx--;
	}
	node = *head;
	idx = 0;
	while (node && idx <= len / 2)
	{
		if (arr[idx] != node->n)
			return (0);
		node = node->next;
		idx++;
	}
	return (1);
}
