def read_file(filename):
    with open(filename, 'r') as file:
        grid = [line.strip() for line in file.readlines()]
    return grid

def count_word_occurrences(grid, word):
    num_rows = len(grid)
    num_cols = len(grid[0])
    total_count = 0
    directions = [
        (0, 1),
        (1, 0),
        (0, -1),
        (-1, 0),
        (1, 1),
        (-1, -1),
        (1, -1),
        (-1, 1)
    ]

    for row in range(num_rows):
        for col in range(num_cols):
            for dx, dy in directions:
                if word_found_from(grid, word, row, col, dx, dy):
                    total_count += 1

    return total_count

def word_found_from(grid, word, start_row, start_col, dx, dy):
    word_len = len(word)
    num_rows = len(grid)
    num_cols = len(grid[0])

    for i in range(word_len):
        row = start_row + i * dx
        col = start_col + i * dy

        if row < 0 or row >= num_rows or col < 0 or col >= num_cols or grid[row][col] != word[i]:
            return False
    return True

def main():
    filename = "day4.txt"
    word = "XMAS"
    grid = read_file(filename)
    total_occurrences = count_word_occurrences(grid, word)
    print(total_occurrences)
main()