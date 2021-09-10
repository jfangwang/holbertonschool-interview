#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Check whether linked list is a cycle or not
 * @list: Linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
*/
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL)
		return (0);

	slow = list;
	fast = list;

	while (fast->next != NULL)
	{
		if (fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return (1);
		}
		else
		{
			return (0);
		}
	}
	return (0);
}
