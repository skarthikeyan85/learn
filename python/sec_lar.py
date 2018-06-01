#!/usr/bin/env python

import sys
import string

def second_largest(n):
    lar = None
    sec_lar = None
    for item in n:
        if lar == None:
            lar = item
        elif item > lar:
            sec_lar = lar
            lar = item
        elif sec_lar == None:
            sec_lar = item
        elif item > sec_lar:
            sec_lar = item
    return sec_lar

def main(argv):
    n = [1, 3, 4, 5, 2]
    sec_lar = second_largest(n)
    print(sec_lar)

if __name__ == "__main__":
      main(sys.argv)
