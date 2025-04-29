'''https://www.codewars.com/kata/54d512e62a5e54c96200019e
5 kyu
'''

def prime_factors(n):
    factors = []
    i = 2
    
    while n > 1:
        while n % i == 0:
            factors.append(i)
            n = n // i
        i += 1
    
    string = ''

    for i in sorted(set(factors)):
        if factors.count(i) > 1:
            string += f"({i}**{factors.count(i)})"
        else:
            string += f"({i})"

    return string