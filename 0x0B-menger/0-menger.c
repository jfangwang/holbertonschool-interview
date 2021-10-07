#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * place_block - determines if the block should be empty or not
 * @col: column
 * @row: row
 * Return: nothing, prints a char
 */
void place_block(int col, int row)
{
	int empty = 0;
	while (col > 0 && row > 0)
	{
		/* The rule */
		if (col % 3 == 1 && row % 3 == 1)
		{
			printf(" ");
			col = 0;
			row = 0;
			empty = 1;
		}
			
		col = col / 3;
		row = row / 3;
	}
	if (empty == 0)
		printf("#");
}

/**
  * menger - prints a 3x3 grid of a menger sponge
  * @level: A level N sponge is a 3x3 square of level N-1 sponges,
  * except for the center one, which is left empty
  * Return: nothing, prints a grid
*/


void menger(int level)
{
	int row = 0;
	int col = 0;
	int dim = 0;

	dim = pow(3, level); /* The height and width of the grid */

	if (level >= 0)
	{
		for (col = 0; col < dim; col++)
		{
			for (row = 0; row < dim; row++)
				place_block(col, row);
			printf("\n");
		}
	}
}

