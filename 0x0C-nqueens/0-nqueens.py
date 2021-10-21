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
        for i in range(1, row + 1):
            for pair in solution:
                if ([row - 1, col - 1] == pair or [row - 1, col + 1] == pair):
                    return False
    return True


def solve(N, solution, row, col, queens):
    """Base Case"""
    if row == N - 1 and col == N:
        return False
    if queens == 0:
        print(solution)
        return True
    """Recursion"""
    if (col < N):
        if valid_place(solution, row, col):
            solution.append([row, col])
            solve(N, solution, row, col + 1, queens - 1)
            solution.remove([row, col])
    else:
        solve(N, solution, row + 1, 0, queens)


check_argv()
for a in range(N):
    solution = []
    solve(N, solution, 0, a, N)
