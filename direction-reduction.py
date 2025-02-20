'''https://www.codewars.com/kata/550f22f4d758534c1100025a
5 kyu
'''
def dir_reduc(arr):
    opposite = {"NORTH": "SOUTH", "SOUTH": "NORTH", "EAST": "WEST", "WEST": "EAST"}
    stack = []

    for direction in arr:
        if stack and stack[-1] == opposite[direction]:
            stack.pop() 
        else:
            stack.append(direction)

    return stack
