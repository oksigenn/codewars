'''https://www.codewars.com/kata/5868b2de442e3fb2bb000119/
5 kyu
'''

def weight(num):
    weight = 0
    while num > 0:
        weight += num % 10
        num = num // 10
    return weight

def closest(string):
    array = string.split()

    array = [[weight(int(num)), i, int(num)] for i, num in enumerate(array)]
    
    array.sort()

    min_weight = float('inf')
    to_return = []

    for i in range(1, len(array)):
        tmp = array[i][0] - array[i-1][0]
        if tmp < min_weight:
            min_weight = tmp
            to_return = [array[i-1], array[i]]

    return to_return