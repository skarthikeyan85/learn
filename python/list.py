#!/usr/bin/env python

import sys
import string

def main(argv):
    list = []
    num = int(raw_input())
    for i in range(num):
        str = raw_input()
        if (str.startswith('print')):
            print(list)
        elif (str.startswith('sort')):
            list.sort()
        elif (str.startswith('pop')):
            list.pop()
        elif (str.startswith('reverse')):
            list.reverse()
        elif (str.startswith('remove')):
            str = string.replace(str, 'remove ', '')
            list.remove(int(str))
        elif (str.startswith('append')):
            str = string.replace(str, 'append ', '')
            list.append(int(str))
        elif (str.startswith('insert')):
            str = string.replace(str, 'insert ', '')
            list.insert(int(str.split()[0]), int(str.split()[1]))

if __name__ == "__main__":
      main(sys.argv)
