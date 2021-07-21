#!/usr/bin/python3
"""
Lockboxes
    Duration of Attempt:
    #1: 52 mins
        Notes: Didn't really know how to structure the recursion exactly
    #2: 72 mins
        Note: Recursion method did not pass checker, don't know why. Chose
        to do it with 2 for loops. Alse changed checked_boxes to int list
        instead of bool list
"""


def canUnlockAll(boxes):
    if boxes is None or len(boxes) == 0:
        return False
    checked_boxes = [0]
    for box in checked_boxes:
        for key in boxes[box]:
            if key < len(boxes) and key not in checked_boxes:
                checked_boxes.append(key)
    if len(checked_boxes) != len(boxes):
        return False
    return True
