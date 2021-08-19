#ifndef _SANDPILES_H_
#define _SANDPILES_H_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
void distribute(int grid[3][3], int row, int col);
void add_grid(int grid1[3][3], int grid2[3][3]);
void reset(int grid[3][3]);

#endif
