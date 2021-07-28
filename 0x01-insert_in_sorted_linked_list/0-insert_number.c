#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Inserts a node in a sorted list
 * @head: pointer to head of list
 * @number: given number to be inserted
 * Return: new node or null
 */


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *curr = *head;
	listint_t *prev = *head;
	listint_t *new;
	int count;

	if (*head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;
	/* Stops at the node that needs to be inserted at*/
	while (curr->next != NULL && curr->n < number)
	{
		if (count > 0)
			prev = prev->next;
		curr = curr->next;
		count = count + 1;
	}
	if (count == 0)
		return (NULL);
	new->next = prev->next;
	prev->next = new;
	return (new);
}
