#!/usr/bin/python3
"""
Lockboxes
    Duration of Attempt:
    #1: 52 mins
        Notes: Didn't really know how to structure the recursion exactly
"""


def canUnlockAll(boxes):
    checked_boxes = ['False'] * len(boxes)
    checked_boxes[0] = 'True'
    if boxes is None or len(boxes) == 0:
        return False
    # print(results)
    if "False" in check_box(boxes[0], checked_boxes, boxes):
        return False
    return True

"""
Recursion
    Input: List of keys in a box
    Output: None, updates checked_boxes list
"""


def check_box(box, checked_boxes, boxes):
    for key in box:
        if key < len(boxes) and checked_boxes[key] is "False":
            checked_boxes[key] = "True"
            check_box(boxes[key], checked_boxes, boxes)
    return checked_boxes
