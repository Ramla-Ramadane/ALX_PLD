#!/usr/bin/python3
for number in range(0, 100):
    print("{:02d}".format(number), end=", " if number != 99 else  '\n') # this very one is to print upto 99 that is why i used the branching.
