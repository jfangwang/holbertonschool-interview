#!/usr/bin/python3
"""Back tracking Method"""
import sys


def check_argv():
    """checks agrv for errors"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    num = 0

    if sys.argv[1].isdigit():
        num = int(sys.argv[1])
        if num is int:
            pass
    else:
        print("N must be a number")
        exit(1)
    num = int(sys.argv[1])
    if num >= 4:
        global N
        N = num
    else:
        print("N must be at least 4")
        exit(1)


def valid_place(solution, row, col):
    """Check if new placement is a valid spot or not"""
    if len(solution) == 0:
        return True
    else:
        """Check the horizontal and vertical"""
        for pair in solution:
            if pair[0] == row or pair[1] == col:
                return False
        """Check for diagonals"""
        for pair in solution:
            for i in range(1, N):
                if ([row - i, col - i] == pair or [row - i, col + i] == pair):
                    return False
    return True


def solve(N, solution, row, queens):
    """Base Case"""
    if queens == 0:
        print(solution)
        return True
    """Recursion"""
    for col in range(N):
        if valid_place(solution, row, col):
            solution.append([row, col])
            solve(N, solution, row + 1, queens - 1)
            """We remove it to check for the next spot even
            if the current [row, col] is true. This will check
            every spot on this row"""
            solution.remove([row, col])


check_argv()
solution = []
solve(N, solution, 0, N)
    
