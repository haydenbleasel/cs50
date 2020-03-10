import csv

from sys import argv, exit

if len(argv) != 3:
    print("Missing argument")
    exit(1)

strs = {}
people = []

# Open the CSV file
with open(argv[1], "r") as file:
    database = csv.DictReader(file)

    for field in database.fieldnames:
        if field != "name":
            strs[field] = 0

    # read contents into memory
    for row in database:
        people.append(row)


# Open the DNA sequence
with open(argv[2], "r") as file:

    # read contents into memory
    for row in file:
        sequence = row

# For each STR
for str in strs:

    longestCount = 0
    count = 0
    lastIndex = 0

    length = len(str)
    distance = len(sequence)

    # For every character in sequence
    for i in range(distance):

        # Get following k-letter sequence
        start = i
        end = start + length
        seq = sequence[start:end]

        # If we find the STR
        if seq == str:

            count += 1

            # If the space between the current and last match index is not exactly the length of the STR
            if (i - lastIndex) > length:

                # Reset the count
                count = 1
                lastIndex = i

            elif (i - lastIndex) == length:

                lastIndex = i

            if count > longestCount:
                longestCount = count

    strs[str] = longestCount

# Compare the STR counts against each row in the CSV file

found = False

for row in people:

    props = {}

    for field in row:
        if field != "name":
            props[field] = int(row[field])

    if (props == strs):
        print(row["name"])
        found = True

if not found:
    print("No match")