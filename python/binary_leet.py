#!/usr/bin/env python

import sys
import string

def addBinary(a, b):
    print a
    print int(a)
    print bin(int(a))
    
def main(argv):
    addBinary("10", "01")

if __name__ == "__main__":
      main(sys.argv)
