'''https://www.codewars.com/kata/5254ca2719453dcc0b00027d/
'''

from itertools import permutations as perm

def permutations(str):
    return set(''.join(i) for i in perm(str))