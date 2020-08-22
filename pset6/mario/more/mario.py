# importing libraries
from cs50 import *
# prompting height
# defining hashes and spaces
hashes = "#"
spaces = " "
i = 0
while True:
    h = get_int("Height: ")
    if h >= 1 and h <= 8:
        break
for i in range(0, h):
    print(spaces * (h-i-1)+hashes * (i+1)+spaces * 2+hashes * (i+1))