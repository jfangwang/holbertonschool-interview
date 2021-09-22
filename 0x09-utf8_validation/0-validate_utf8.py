#!/usr/bin/python3
"""Validate UTF-8 Encoding"""

def validUTF8(data):
    for item in data:
        if (item >= 256):
            return False
    return True
        