#!/usr/bin/python3
# Prints the last digit of a number

def print_last_digit(number):
    last_digit = abs(number) % 10
    print(last_digit, end='')
    return last_digit

if __name__ == '__main__':
    num = 3211
    while num:
        print_last_digit(num)
        num = int(num / 10)
    print()
