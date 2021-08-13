#!/usr/bin/python3
"""Operations, its the sum of prime numbers"""


def minOperations(n):
    actions = 0
    i = 2
    for i in range(2, n+1):
        while (n % i == 0):
            n = n / i
            actions = actions + i
    return actions
