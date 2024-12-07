def read_file(filename):
    with open(filename, 'r') as file:
        grid = [line.strip() for line in file.readlines()]
    return grid

def count_cross(grid, center_char, char1, char2):
    rows, cols = len(grid), len(grid[0])
    count = 0

    for row in range(1, rows - 1):
        for col in range(1, cols - 1):
            if grid[row][col] == center_char:
                top_left_bottom_right = (grid[row - 1][col - 1] == char1 and grid[row + 1][col + 1] == char2) or (grid[row - 1][col - 1] == char2 and grid[row + 1][col + 1] == char1) 
                top_right_bottom_left = (grid[row - 1][col + 1] == char2 and grid[row + 1][col - 1] == char1) or (grid[row - 1][col + 1] == char1 and grid[row + 1][col - 1] == char2)
                if top_left_bottom_right and top_right_bottom_left:
                    count += 1
    return count

def main():
    filename = "day4.txt"
    center_char = "A"
    char1 = "M"
    char2 = "S"
    grid = read_file(filename)
    total_cross = count_cross(grid, center_char, char1, char2)
    print(total_cross)

main()