#!/usr/bin/python3
"""Operations"""


def minOperations(n):
    num = 1
    actions = 0
    paste = 1
    return recurse(num, actions, paste, n)


def recurse(num, actions, paste, n):
    if n < 1 or num > n:
        return (actions)
    path1 = recurse(num + paste, actions + 1, paste, n)
    path2 = recurse(num * 2, actions + 2, num, n)
    if path1 < path2:
        return path1
    return path2
