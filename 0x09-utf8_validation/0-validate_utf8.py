#!/usr/bin/python3
"""Validate UTF-8 Encoding"""

"""
128 | 64  | 32  | 16  |  8  |  4  |  2  |  1  |
 1     1     1     1     1     1     1     1

 1     0     0     0     0     0     0     0  = 128
 1     1     0     0     0     0     0     0  = 192
 1     1     1     0     0     0     0     0  = 224
 1     1     1     1     0     0     0     0  = 240
"""


def validUTF8(data):

    byte_count = 0
    for item in data:
        """Want to check how many bytes there are"""
        
        print(item, bin(item)[2:], byte_count)
        item = bin(item)[2:]
        if (byte_count == 0):
            index = 0
            while (item[index] == "1"):
                byte_count = byte_count + 1
                index = index + 1
            if (byte_count == 1):
                byte_count = 0
            else:
                byte_count = byte_count - 1
        else:
            if (item[byte_count - 1] != "1"):
                return False
            byte_count = byte_count - 1
    return True