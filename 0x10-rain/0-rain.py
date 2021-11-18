#!/usr/bin/python3
"""The rain problem"""


def rain(walls):
    """Problem Statement: Given a list of non-negative integers representing
    the heights of walls with unit width 1, as if viewing the cross-section
    of a relief map, calculate how many square units of water will be retained
    after it rains."""

    """  0 2 1 0 4 0 2 0 1 0 5 0 """
    """  0 2 1 0 4 0 2 0 1 0 5 0 """

    sum = 0
    new_walls = reduce_wall(walls)

    while len(new_walls) > 0:
        sum += new_walls.count(0)
        for item in range(0, len(new_walls)):
            if new_walls[item] > 0:
                new_walls[item] = new_walls[item] - 1
        new_walls = reduce_wall(new_walls)
    return sum


def reduce_wall(walls):
    """Remove any zeros that are not between two nums above 0"""

    """Check if there are any walls"""
    index, beg, end = 0, 0, len(walls) - 1
    if len(set(walls)) < 2:
        return []
    """Clearing the beginning"""
    while index < len(walls) and walls[index] == 0:
        index += 1
    beg = index
    index = len(walls) - 1
    while index > 0 and walls[index] == 0:
        index -= 1
    end = index
    return walls[beg: end + 1]
