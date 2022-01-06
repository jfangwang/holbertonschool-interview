#!/usr/bin/python3
"""Given an n x n 2D matrix, rotate it 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    for i in range(0, round(len(matrix) / 2)):
        nums = []
        # Top Row
        nums.append(matrix[0][i])

        # Right Column
        nums.append(matrix[i][len(matrix) - 1])
        matrix[i][len(matrix) - 1] = nums.pop(0)

        # Bottom Row
        nums.append(matrix[len(matrix) - 1][len(matrix) - 1 - i])
        matrix[len(matrix) - 1][len(matrix) - 1 - i] = nums.pop(0)

        # Left Column
        nums.append(matrix[len(matrix) - 1 - i][0])
        matrix[len(matrix) - 1 - i][0] = nums.pop(0)

        # Replace Top Row
        matrix[0][i] = nums.pop(0)

# [1, 2, 3],
# [4, 5, 6],
# [7, 8, 9]]

# [7, 2, 1], 
# [4, 5, 6], 
# [9, 8, 3]