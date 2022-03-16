#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """Main Function"""
    if (n <= 0):
        return ([])
    if (n == 1):
        return ([[1]])
    output = [[1], [1, 1]]
    if (n == 2):
        return output

    def solve(arr, n):
        """Recursion function"""
        if (n <= 0):
            return output

        new = [1]

        for i in range(0, len(arr) - 1):
            first = arr[i]
            second = arr[i + 1]
            new.append(first + second)
        new.append(1)
        output.append(new)
        return solve(new, n - 1)
    return solve([1, 1], n - 2)
