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
        for l in range(0, N):
            if (k + l == col + row) or (k - l == row - col):
                if board[k][l] == 1:
                    return False
    return True

global tried_spots
tried_spots = []


def solve(queens, tried_spots):
    """Backtrace Method"""
    if queens == 0:
        global answer
        answer = []
        right = True
        for a in range(len(tried_spots) - N, len(tried_spots)):
            answer.append(tried_spots[a])
        for i in range(N):
            if (answer[i][0] != i):
                right = False
            for j in range(i + 1, N):
                if answer[i] == answer[j]:
                    right = False
        if right == True:
            print("{}".format(answer))
    for row in range(0, N):
        for col in range(0, N):
            if valid_place(row, col) is True and board[row][col] != 1:
                board[row][col] = 1
                tried_spots.append([row, col])
                # recursive part
                if solve(queens - 1, tried_spots) is True:
                    return True
                board[row][col] = 0
    return False

check_argv()
board = [[0]*N for a in range(N)]
solve(N, tried_spots)