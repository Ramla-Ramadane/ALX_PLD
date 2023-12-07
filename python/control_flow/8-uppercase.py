#!/usr/bin/python3
# prints a string in uppercase followed by a new line

def uppercase(str):
    for ch in str:
        a = ord(ch)
        if 97 <= a <= 122:
            a = a - 32
        print("{:s}".format(chr(a)), end='')
    print()

if __name__ == '__main__':
    uppercase("Abc")
