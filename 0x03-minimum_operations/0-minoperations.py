#!/usr/bin/python3
"""Operations, its the sum of prime numbers"""


def minOperations(n):
    actions = 0
    i = 2
    while n > 1 and i <= n:
        while (n % i == 0):
            n = n / i
            actions = actions + i
        i = i + 1
    return actions
