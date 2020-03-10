from cs50 import get_float

dollars = -1

quarter = 25
dime = 10
nickel = 5
penny = 1

while dollars < 0:
    dollars = get_float("Change owed: ")

coins = round(dollars * 100)

sum = 0

while coins > 0:
    sum += 1

    if coins >= 25:
        coins -= 25
    elif coins >= 10:
        coins -= 10
    elif coins >= 5:
        coins -= 5
    elif coins >= 1:
        coins -= 1

print(sum)