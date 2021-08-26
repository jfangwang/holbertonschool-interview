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
	while (len >= 0)
	{
		arr[len] = node->n;
		node = node->next;
		len--;
	}
	node = *head;
	len++;
	while (node)
	{
		if (arr[len] != node->n)
			return (0);
		node = node->next;
		len++;
	}
	return (1);
}
