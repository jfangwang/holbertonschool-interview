#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * distribute - distribute piles
 * @grid: grid
 * @row: row number
 * @col: col number
 * Retrun: None
 */
void distribute(int grid[3][3], int row, int col)
{
	/* UP */
	if (row > 0)
		grid[row - 1][col] = grid[row - 1][col] + 1;
	/* RIGHT */
	if (col < 2)
		grid[row][col + 1] = grid[row][col + 1]  + 1;
	/* BOTTOM */
	if (row < 2)
		grid[row + 1][col] = grid[row + 1][col] + 1;
	/* LEFT */
	if (col > 0)
		grid[row][col - 1] = grid[row][col - 1] + 1;
}

/**
 * add_grid - add matrix 1 and 2 to matrix 1. Sets grid2 values to -1.
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * Return: None
 */
void add_grid(int grid1[3][3], int grid2[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			grid1[row][col] = grid1[row][col] + grid2[row][col];
	print_grid(grid1);
}

/**
 * reset - reset grid to all -1
 * @grid: 3x3 grid
 * Return: None
 */
void reset(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid[row][col] = -1;
		}
	}
}

/**
 * sandpiles_sum - returns sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * Return: None
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int copy[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			grid1[row][col] = grid1[row][col] + grid2[row][col];
	while (grid1[0][0] > 3 || grid1[0][1] > 3 || grid1[0][2] > 3 ||
		   grid1[1][0] > 3 || grid1[1][1] > 3 || grid1[1][2] > 3 ||
		   grid1[2][0] > 3 || grid1[2][1] > 3 || grid1[2][2] > 3)
	{
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				copy[row][col] = grid1[row][col];
		print_grid(grid1);
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (grid1[row][col] > 3)
				{
					/* UP */
					if (row > 0)
						copy[row - 1][col] = copy[row - 1][col] + 1;
					/* RIGHT */
					if (col < 2)
						copy[row][col + 1] = copy[row][col + 1]  + 1;
					/* BOTTOM */
					if (row < 2)
						copy[row + 1][col] = copy[row + 1][col] + 1;
					/* LEFT */
					if (col > 0)
						copy[row][col - 1] = copy[row][col - 1] + 1;
					copy[row][col] = copy[row][col] - 4;
				}
			}
		}
		for (row = 0; row < 3; row++)
			for (col = 0; col < 3; col++)
				grid1[row][col] = copy[row][col];
	}
}
