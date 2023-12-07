#!/usr/bin/python3
# Print all different combinations
for a in range(0, 9):
    for b in range(a + 1, 10):
        print("{:d}{:d}".format(a, b), end=", " if a + b != 17 else "\n")
