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
    for num in data:
        """Transform into binary"""
        bin_rep = format(num, '#010b')[-8:]

        "Check if num is part of a series of bytes or a new byte"
        if byte_count == 0:

            """Check how many bytes in num"""
            for bit in bin_rep:
                if bit == '0':
                    break
                else:
                    byte_count = byte_count + 1
            """skip if byte count is 1"""
            if byte_count == 0:
                continue
            if byte_count == 1 or byte_count > 4:
                return False
        else:
            """Part of a series of bytes"""
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False
        byte_count = byte_count - 1
    if (byte_count == 0):
        return True
    return False
