#!/usr/bin/python3
# Checks for lowercases

def islower(c):
    ch = ord(c)
    if 96 < ch < 123:
        return True
    return False

#if __name__ == '__main__':
retval = islower('c')
print("Executing in 7-islower")
