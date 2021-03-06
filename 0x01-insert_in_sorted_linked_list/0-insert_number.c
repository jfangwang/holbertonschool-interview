#include <stdlib.h>
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
	listint_t *prev = NULL;
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	while (curr != NULL && curr->n < number)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
	{
		*head = new;
		new->next = curr;
	}
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
	return (new);
}
