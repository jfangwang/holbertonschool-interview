#!/usr/bin/python3
<<<<<<< HEAD
""" coin problem """

def makeChange(coins, total):

=======
""" Making Change """


def makeChange(coins, total):
    """Main Method"""
    coin_count = 0
    cur_total = 0
    if total <= 0:
        return (0)
    coins.sort(reverse=True)
    while len(coins) > 0 and cur_total <= total:
        if cur_total == total:
            return coin_count
        if coins[0] > total - cur_total:
            coins.pop(0)
        else:
            cur_total += coins[0]
            coin_count += 1
    return (-1)
>>>>>>> 602ce0432fde5b628c2319a3be608ee04d93ed9a
