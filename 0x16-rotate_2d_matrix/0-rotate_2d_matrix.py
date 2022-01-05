#!/usr/bin/python3
"""Given an n x n 2D matrix, rotate it 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    for i in range(0, len(matrix) - 1):
        # Top to Right
        temp = matrix[i][-1]
        matrix[i][-1] = matrix[0][i]
        # Right to Bottom
        temp2 = matrix[len(matrix) - 1][len(matrix) - i - 1]
        matrix[len(matrix) - 1][len(matrix) - i - 1] = temp
        # Bottom to Left
        temp = matrix[len(matrix) - 1 - i][0]
        matrix[len(matrix) - 1 - i][0] = temp2
        # Left to Top
        matrix[0][i] = temp
