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


def valid_place(row, col):
    """checks if a queen can be placed without interferance"""
    # check row and col
    for a in range(N):
        if board[row][a] == 1 or board[a][col] == 1:
            return False
    # check diagonals
    for k in range(0, N):
        for j in range(0, N):
            if (k + j == col + row) or (k - j == row - col):
                if board[k][j] == 1:
                    return False
    return True


def solve(queens, tried_spots, answer):
    """Backtrace Method"""
    if (queens == 0):
        if [] not in tried_spots:
            print(tried_spots)
    for row in range(0, N):
        for col in range(0, N):
            if valid_place(row, col) is True and board[row][col] != 1:
                board[row][col] = 1
                tried_spots[row] = [row, col]
                for clear in range(row + 1, N):
                    tried_spots[clear] = []
                # recursive part
                solve(queens - 1, tried_spots, answer)
                board[row][col] = 0


check_argv()
board = [[0]*N for a in range(N)]
tried_spots = [[] for a in range(N)]
solve(N, tried_spots, [])
