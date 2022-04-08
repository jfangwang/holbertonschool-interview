#!/usr/bin/python3
"""Prime Game"""


def isWinner(x, nums):
    """isWinner"""
    if not nums or x < 1:
        return None
    ben = 0
    maria = 0
    for i in range(0, x):
        prime = []

        # find prime numbers
        for j in range(1, nums[i] + 1):
            isPrime = True
            for k in range(2, j):
                if (j % k == 0):
                    isPrime = False
            if (isPrime):
                prime.append(j)
        if (len(prime) % 2 == 0):
            maria += 1
        else:
            ben += 1
    if (ben == maria):
        return None
    if (ben > maria):
        return ('Ben')
    return ('Maria')
