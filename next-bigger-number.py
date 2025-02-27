'''https://www.codewars.com/kata/55983863da40caa2c900004e
4 kyu
'''

def next_bigger(n):
    digits = list(str(n))
    length = len(digits)
    
    i = length - 2
    while i >= 0 and digits[i] >= digits[i + 1]:
        i -= 1
    
    if i == -1:
        return -1
    
    j = length - 1
    while digits[j] <= digits[i]:
        j -= 1
    
    digits[i], digits[j] = digits[j], digits[i]
    
    digits = digits[:i + 1] + sorted(digits[i + 1:])
    
    return int("".join(digits))
