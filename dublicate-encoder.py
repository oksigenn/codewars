'''https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/
6 kyu
'''

def duplicate_encode(word):
    word = word.lower()
    tmp = ""
    for i in range(len(word)):
        letter = word[i]
        tmp+=')' if word.count(letter) > 1 else '('

    return tmp