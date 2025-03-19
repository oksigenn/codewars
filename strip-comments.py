'''https://www.codewars.com/kata/51c8e37cee245da6b40000bd
4 kyu
'''

def strip_comments(string, markers):
    tmp = string.split('\n')

    for i in range(len(tmp)):
        line = tmp[i]

        for marker in markers:
            index = line.find(marker)

            if index != -1:
                line = line[:index]
        tmp[i] = line.rstrip()

    return '\n'.join(tmp)   