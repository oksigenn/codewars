from collections import deque

'''https://www.codewars.com/kata/5672682212c8ecf83e000050
4 kyu
'''

def dbl_linear(n):
    u = [1]
    Q2, Q3 = deque([3]), deque([4])
    
    for _ in range(n):
        next_val = min(Q2[0], Q3[0])
        u.append(next_val)

        if next_val == Q2[0]:
            Q2.popleft()
        if next_val == Q3[0]:
            Q3.popleft()

        Q2.append(2 * next_val + 1)
        Q3.append(3 * next_val + 1)

    return u[n]
