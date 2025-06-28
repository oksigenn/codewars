'''https://www.codewars.com/kata/5d6a11ab2a1ef8001dd1e817
6 kyu
'''

def connect_the_dots(paper):
    lines = paper.splitlines()
    height, width = len(lines), len(lines[0])

    grid = [list(line) for line in lines]
    points = {}
    
    for i, row in enumerate(grid):
        for y, char in enumerate(row):
            if 'a' <= char <= 'z':
                points[char] = (i, y)
                grid[i][y] = ' '

    letters = sorted(points.keys())
    sorted_points = [points[ch] for ch in letters]
    
    #drawing
    for (y1, x1), (y2, x2) in zip(sorted_points, sorted_points[1:]):
        dy = y2 - y1
        dx = x2 - x1

        step_y = (dy > 0) - (dy < 0)
        step_x = (dx > 0) - (dx < 0)

        y, x = y1, x1
        while (y, x) != (y2, x2):
            grid[y][x] = '*'
            y += step_y
            x += step_x
        grid[y2][x2] = '*'

    return '\n'.join(''.join(row) for row in grid) + '\n'