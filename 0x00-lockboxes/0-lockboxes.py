#!/usr/bin/python3
"""
Lockboxes
    Duration of Attempt:
    #1: 52 mins
        Notes: Didn't really know how to structure the recursion exactly
"""


def canUnlockAll(boxes):
    if boxes is None or len(boxes) == 0:
        return False
    checked_boxes = [0]
    if len(check_box(boxes[0], checked_boxes, boxes)) != len(boxes):
        return False
    return True

"""
Recursion
    Input: List of keys in a box
    Output: None, updates checked_boxes list
"""


def check_box(box, checked_boxes, boxes):
    for key in box:
        if key < len(boxes) and key not in checked_boxes:
            checked_boxes.append(key)
            check_box(boxes[key], checked_boxes, boxes)
    return checked_boxes
