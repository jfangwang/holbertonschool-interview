#!/usr/bin/python3
"""Operations"""


def minOperations(n):
    num = 1
    actions = 0
    paste = 0
    if n < 1:
        return 0
    return recurse(num, actions, paste, n)


def recurse(num, actions, paste, n):
    path1 = None
    if num > n:
        return (num)
    if num == n:
        return (actions)
    if (paste != 0):
        path1 = recurse(num + paste, actions + 1, paste, n)
    path2 = recurse(num * 2, actions + 2, num, n)
    if path1 is None or path2 < path1:
        return path2
    return path1
