from cs50 import get_int

height = -1

while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):

    h = i + 1

    for j in range(height - h):
        print(" ", end="")

    for j in range(h):
        print("#", end="")

    print()