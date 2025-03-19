'''https://www.codewars.com/kata/525f3eda17c7cd9f9e000b39
5 kyu
'''

def zero(operation=None): return 0 if operation is None else operation(0)
def one(operation=None): return 1 if operation is None else operation(1)
def two(operation=None): return 2 if operation is None else operation(2)
def three(operation=None): return 3 if operation is None else operation(3)
def four(operation=None): return 4 if operation is None else operation(4)
def five(operation=None): return 5 if operation is None else operation(5)
def six(operation=None): return 6 if operation is None else operation(6)
def seven(operation=None): return 7 if operation is None else operation(7)
def eight(operation=None): return 8 if operation is None else operation(8)
def nine(operation=None): return 9 if operation is None else operation(9)

def plus(operand): 
    return lambda x: x + operand
def minus(operand): 
    return lambda x: x - operand
def times(operand):
    return lambda x: x * operand
def divided_by(operand):
    return lambda x: x // operand