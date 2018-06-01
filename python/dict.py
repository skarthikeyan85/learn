#!/usr/bin/env python

import sys
import string

def find_dup_list(l):
    n = {}
    for item in l:
        if (item in n):
            print(item)
        n[item] = 1

def find_pair(l, val):
    n = {}
    for item in l:
        if (item in n):
            print n[item], item
            return
        n[val - item] = item
    print (" %d is not found " % val)
    return

def main(argv):
    '''
    d = {'emily':32, 'tom':43}
    d['tom']=45
    d['george']=45
    print d
    '''
    l = ['Tom','George','Jen','Tom']
    find_dup_list(l)
    nums = [1,3,4,9,12]
    find_pair(nums, 21)
    find_pair(nums, 32)

if __name__ == "__main__":
      main(sys.argv)
