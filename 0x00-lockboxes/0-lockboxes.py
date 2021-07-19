#!/usr/bin/python3
"""
Lockboxes
    Duration of Attempt:
    #1: 52 mins
        Notes: Didn't really know how to structure the recursion exactly
"""

def canUnlockAll(boxes):
    num_boxes = len(boxes)
    checked_boxes = ['False'] * num_boxes
    checked_boxes[0] = 'True'
    results = check_box(boxes[0], checked_boxes, boxes)
    for a in results:
        if a is "False":
            return False
    return True

"""
Recursion
    Input: List of keys in a box
    Output: None, updates checked_boxes list
"""
def check_box(box, checked_boxes, boxes):
    for key in box:
        if checked_boxes[key] is "False":
            checked_boxes[key] = "True"
            check_box(boxes[key], checked_boxes, boxes)
    return checked_boxes