#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: head of a linked list
 * Return: The address of the node where the loop starts or
 * NULL if there is no loop
 * Description: A -> B -> C
 *					 ^    |
 *					 |    v
 *					 E <- D
 *	Loop starts at node B, returns node B
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1 = head;
	listint_t *p2 = head;

	if (!head || head->next == NULL)
		return (NULL);

	while (p2)
	{
		p1 = p1->next;
		if (p2->next == NULL)
			return (NULL);
		p2 = p2->next->next;

		if (p1 == p2)
		{
			/* Reset p1 to head to find the intersection */
			p1 = head;
			while (p1 != p2)
			{
				/* p1 and p2 will hit each other when the loop starts */
				p1 = p1->next;
				p2 = p2->next;
			}
			return (p1);
		}
	}
	return (NULL);
}


