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
 * @row: row number
 * @col: col number
 * Retrun: None
 */
void distribute(int grid1[3][3], int row, int col) {
    /* UP */
    if (row > 0) {
        grid1[row - 1][col] = grid1[row - 1][col] + 1;
    }
    /* RIGHT */
    if (col < 2) {
        grid1[row][col + 1] = grid1[row][col + 1]  + 1;
    }
    /* BOTTOM */
    if (row < 2) {
        grid1[row + 1][col] = grid1[row + 1][col] + 1;
    }
    /* LEFT */
    if (col > 0) {
        grid1[row][col - 1] = grid1[row][col - 1] + 1;
    }
}

/**
 * add_grid - add matrix 1 and 2 to matrix 1. Sets grid2 values to -1.
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * Return: None
 */
void add_grid(int grid1[3][3], int grid2[3][3]) {
    int row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            grid1[row][col] = grid1[row][col] + grid2[row][col];
            grid2[row][col] = -1;
        }
    }
    reset1(grid2);
}

/**
 * reset1 - reset grid to all -1
 * @grid1: 3x3 grid
 * Return: None
 */
void reset1(int grid1[3][3]) {
    int row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            grid1[row][col] = -1;
        }
    }
}

/**
 * sandpiles_sum - returns sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * Return: None
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int row, col;
    int stable = 1;

    if (grid2[0][0] != -1) {
        add_grid(grid1, grid2);
        print_grid(grid1);
    }
    /* Set grid 2 to grid 1 */
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            grid2[row][col] = grid1[row][col];
        }
    }
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (grid1[row][col] > 3) {
                distribute(grid2, row, col);
                grid2[row][col] = grid2[row][col] - 4;
            }
        }
    }
    /* Set grid 1 to new grid (grid 2) */
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            grid1[row][col] = grid2[row][col];
            if (grid1[row][col] > 3)
                stable = 0;
        }
    }
    reset1(grid2);
    if (stable == 0) {
        print_grid(grid1);
        sandpiles_sum(grid1, grid2);
    }
}