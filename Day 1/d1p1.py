def calculate_distance(arr1, arr2):
    sum_dist = 0
    for i in range(min(len(arr1), len(arr2))):
        sum_dist += abs(arr1[i] - arr2[i])
    return sum_dist

def main():
    arrX = []
    arrY = []

    with open("Day1.txt", "r") as code:
        data = code.readlines()

    for line in data:
        x, y = line.split("   ")
        arrX.append(int(x));
        arrY.append(int(y));

    arrY.sort()
    arrX.sort()

    print(calculate_distance(arrX, arrY))


main()