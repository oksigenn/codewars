'''https://www.codewars.com/kata/54d496788776e49e6b00052f
4 kyu
'''

def sum_for_list(list):
    result = []

    isnegative = False
    primes = set()
    for num in list:
        isnegative = True if num < 0 else False
        n = abs(num)
        i = 2
        if n % i == 0:
            primes.add(i)
            while n % i == 0:
                n //= i
        i = 3
        while i <= n**2:
            if n % i == 0:
                primes.add(i)
                while n % i == 0:
                    n //= i
            i += 2
    
    for p in sorted(primes):
        sum = 0
        for num in list:
            if num % p == 0:
                sum += num
        if sum != 0 or isnegative:
            result.append([p, sum])
    
    return result