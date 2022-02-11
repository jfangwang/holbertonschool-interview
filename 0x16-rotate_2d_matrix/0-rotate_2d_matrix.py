#!/usr/bin/python3
"""Given an n x n 2D matrix, rotate it 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    new_matrix = []
    for col in range(0, len(matrix)):
        temp = []
        for row in range(len(matrix) - 1, -1, -1):
            temp.append(matrix[row][col])
        new_matrix.append(temp)
    for row in range(0, len(matrix)):
        for col in range(0, len(matrix)):
            matrix[row][col] = new_matrix[row][col]
