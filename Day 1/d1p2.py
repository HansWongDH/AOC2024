
def calculate_occurance(mapx, arry):
    for num in arry:
        if num in mapx:
            mapx[num] += 1;

    total_sum = sum(key * value for key, value in mapx.items())
    return total_sum

def main():
    mapX = {}
    arrY = []

    with open("Day1.txt", "r") as code:
        data = code.readlines()

    for line in data:
        x, y = line.split()
        x = int(x)
        y = int(y)
        if x not in mapX:
            mapX[x] = 0
        
        arrY.append(y)

    print("answer is ", calculate_occurance(mapX, arrY))


main()