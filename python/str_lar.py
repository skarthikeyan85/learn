#!/usr/bin/env python

import sys
import string

def larger_str(one, two):
    if (len(one) > len(two)):
        return True
    if (len(one) < len(two)):
        return False 

    for i in range(len(one)):
        if (one[i] == two[i]):
            continue
        if (one[i] > two[i]):
            return True
        if (one[i] < two[i]):
            return False

    return False

def main(argv):
    a = "1234"
    b = "1222"
    print larger_str(a,b)

if __name__ == "__main__":
      main(sys.argv)
