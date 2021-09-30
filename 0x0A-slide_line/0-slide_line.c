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

static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

int slide_line(int *line, size_t size, int direction)
{
	size_t start = 0;
	size_t scout = 0;
	size_t match_num = 0;

	if (direction == SLIDE_LEFT)
	{
		for (start = 1; start < size; start++)
		{
			print_array(line, size);
			scout = start;
			if (line[start - 1] != 0)
			{
				// If new prospect is not a 0
				match_num = (size_t)line[start - 1];
			} else {
				// Find the next num and use it for match num
				while (scout < size) {
					if (line[scout] != 0)
					{
						match_num = (size_t)line[scout];
						line[start - 1] = line[scout];
						line[scout] = 0;
						scout = size;
						printf("%ls", line);
					}
					scout = scout + 1;
				}
				if (match_num == 0)
					return (1);
			}
			scout = start;
			printf("%ld \n", match_num);
			while (scout < size)
			{
				// Look for the next matching num
				if (line[scout] != 0)
				{
					if ((size_t)line[scout] == match_num)
					{
						line[start - 1] = line[scout] * 2;
						line[scout] = 0;
					}	
				}
				scout = scout + 1;
			}
		}
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		return (1);
	}
	return (1);
}
