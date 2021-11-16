#!/usr/bin/python3
"""The rain problem"""


def rain(walls):
    """Problem Statement: Given a list of non-negative integers representing
    the heights of walls with unit width 1, as if viewing the cross-section
    of a relief map, calculate how many square units of water will be retained
    after it rains."""
    prev_wall, next_wall, width, sum = 0, 0, 0, 0

    for box in walls:
        if box > 0:
            if prev_wall > 0 and next_wall == 0:
                next_wall = box
            if prev_wall == 0:
                prev_wall = box
                width = 0
        else:
            width += 1
        if prev_wall > 0 and next_wall > 0:
            if prev_wall < next_wall:
                sum += prev_wall * width
            else:
                sum += next_wall * width
            prev_wall = next_wall
            width = 0
            next_wall = 0
    return sum
