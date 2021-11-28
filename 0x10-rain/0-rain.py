#!/usr/bin/python3
"""The rain problem"""


def rain(walls):
    """Problem Statement: Given a list of non-negative integers representing
    the heights of walls with unit width 1, as if viewing the cross-section
    of a relief map, calculate how many square units of water will be retained
    after it rains."""
    """  [0, 1, 0]                -> 0 """
    """  [0, 1, 0, 2, 0, 3, 0, 4] -> 6"""
    """  [2, 0, 1, 0, 3]          -> 5 """

    sum, new_walls = 0, reduce_wall(walls)

    while len(new_walls) > 0:
        sum += new_walls.count(0)
        new_walls = [i - 1 if i > 0 else i for i in new_walls]
        new_walls = reduce_wall(new_walls)
    return sum


def reduce_wall(walls):
    """Remove any zeros that are not between two nums above 0"""
    beg, end = 0, len(walls) - 1
    if len(set(walls)) < 2:
        return []
    while beg < len(walls) and walls[beg] == 0:
        beg += 1
    while end > 0 and walls[end] == 0:
        end -= 1
    return walls[beg: end + 1]
