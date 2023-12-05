#!/usr/bin/python3
# Print alphabet in lowercase leaving out q and e
for letter in range(97, 123):
    a = chr(letter)
    if a not in "qe":
        print("{:s}".format(a), end="")
print()
