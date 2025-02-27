'''https://www.codewars.com/kata/51e04f6b544cf3f6550000c1
5 kyu
'''

def beeramid(bonus, price):
    counter = 0
    levels = 0

    if bonus < price:
        return 0

    while bonus >= price * counter ** 2:
        bonus -= price * counter ** 2
        counter += 1
        levels += 1
    return levels - 1