#!/usr/bin/env python

import sys
import string

def main(argv):
    a = ["item1", "item2"]
    print (a[1])
    print (len(a))
    print ("items: ")
    for item in a:
        print (item)
    print ("range: ")
    a[1] = "change"
    for i in range(len(a)):
        print (a[i])
    n = [1, 2]
    sum = 0
    for item in n:
        sum += item
    print (sum)

if __name__ == "__main__":
      main(sys.argv)
