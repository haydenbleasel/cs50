from cs50 import SQL
import csv
from sys import argv, exit

# Accept a command line argument
if len(argv) != 2:
    print("Missing argument")
    exit(1)

# Connect to database
db = SQL("sqlite:///students.db")

# Lookup students by house
students = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last", argv[1])

# For each student
for student in students:

    # Calculate middle name
    middle = f" {student['middle']} " if student['middle'] else " "

    # Print out student
    print(f"{student['first']}{middle}{student['last']}, born {student['birth']}")