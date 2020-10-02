# TODO
import cs50
from csv import reader
from sys import argv

# open the database to be used later
db = cs50.SQL("sqlite:///students.db")

# check whether there is an input
if len(argv) < 2:
    print("usage error, import.py characters.csv")
    exit()
# open csv and copy into a list
with open(argv[1], newline='') as charactersFile:
    characters = reader(charactersFile)
    for character in characters:
        if character[0] == 'name':
            continue
        # split the full name into first, last and middle name if present
        fullName = character[0].split()
        # insert the name and the other info in the database
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], None, fullName[1], character[1], character[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], fullName[1], fullName[2], character[1], character[2])