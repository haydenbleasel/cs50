from cs50 import SQL
import csv
from sys import argv, exit

# Accept a command line argument
if len(argv) != 2:
    print("Missing argument")
    exit(1)

# Make sure students.db exists
open("students.db", "w").close()

# Connect to database
db = SQL("sqlite:///students.db")

# Create a new students table
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

# Open the CSV file
with open(argv[1], "r") as file:

    # Read the CSV file
    database = csv.reader(file)

    # For each row in the database
    for name, house, birth in database:

        # If this isn't the first row
        if name != "name":

            # Split the name and figure out first, last and middle
            splitName = name.split()
            first = splitName[0]
            last = splitName[-1]
            middle = splitName[1] if len(splitName) > 2 else None

            # Create sql command
            command = "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)"

            # Enter into database
            db.execute(command, first, middle, last, house, birth)