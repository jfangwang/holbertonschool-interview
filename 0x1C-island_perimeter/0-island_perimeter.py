#!/usr/bin/python3
"""island perimeter"""


def check_perimeter(grid, row, col):
    count = 0
    if (row - 1 >= 0 and grid[row - 1][col] == 0):
        count += 1
    if (row + 1 < len(grid) and grid[row + 1][col] == 0):
        count += 1
    if (col - 1 >= 0 and grid[row][col - 1] == 0):
        count += 1
    if (col + 1 < len(grid) and grid[row][col + 1] == 0):
        count += 1
    return (count)


def island_perimeter(grid):
    visited = []
    sum = 0

    for row in range(0, len(grid)):
        for col in range(0, len(grid)):
            if (grid[row][col] == 1 and (row, col) not in visited):
                visited.append((row, col))
                sum += check_perimeter(grid, row, col)
    return sum
