#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
  * slide_line - slides and merges an array of integers
  * @line: Pointer to an array of integers
  * @size: Number of elements
  * @direction: slide left or slide right
  * Return: 1 success, 0 failure
*/

int slide_line(int *line, size_t size, int direction)
{
	size_t placement, count = 0;

	if (direction == SLIDE_LEFT)
	{
		shift_all_left(line, size);
		for (placement = count; placement < size; placement++)
		{
			if (placement + 1 < size && line[placement] == line[placement + 1])
			{
				line[placement] *= 2;
				line[placement + 1] = 0;
			}
		}
		shift_all_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		shift_all_right(line, size);
		for (placement = size; placement > 0; placement--)
		{
			if (line[placement - 1] == line[placement - 2])
			{
				line[placement - 2] *= 2;
				line[placement - 1] = 0;
			}
		}
		shift_all_right(line, size);
	}
	return (1);
}

/**
  * shift_all_left - Shifts all numbers to the left
  * @line: Pointer to an array of integers
  * @size: Number of elements
  * Return: Void
*/

void shift_all_left(int *line, size_t size)
{
	size_t scout, placement = 0;

	for (placement = 0; placement < size; placement++)
	{
		/* Shift all numbers to the left */
		if (line[placement] == 0)
		{
			scout = placement;
			while (line[scout] == 0)
				scout++;
			if (scout < size)
			{
				line[placement] = line[scout];
				line[scout] = 0;
			}
		}
	}
}

/**
  * shift_all_right - Shifts all numbers to the right
  * @line: Pointer to an array of integers
  * @size: Number of elements
  * Return: Void
*/

void shift_all_right(int *line, size_t size)
{
	int scout, placement = 0;

	for (placement = size; placement > 0; placement--)
	{
		/* Shift all numbers to the right */
		placement--;
		if (line[placement] == 0)
		{
			scout = placement;
			while (line[scout] == 0)
				scout--;
			if (scout > -1)
			{
				line[placement] = line[scout];
				line[scout] = 0;
			}
		}
		placement++;
	}
}
