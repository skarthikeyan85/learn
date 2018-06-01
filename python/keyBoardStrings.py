#!/usr/bin/env python
import socket
import subprocess
import sys
import json 
from datetime import datetime

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        retList = []
        d = {'q': 1, 'w': 1, 'e': 1, 'r': 1, 't': 1, 'y': 1,'u': 1, 'i': 1, 'o': 1, 'p': 1,\
             'a': 2, 's': 2, 'd': 2, 'f': 2, 'g': 2, 'h': 2,'j': 2, 'k': 2, 'l': 2,\
             'z': 3, 'x': 3, 'c': 3, 'v': 3, 'b': 3, 'n': 3,'m': 3} 
        for s in words:
            last = 0
            ret = False
            for c in s:
                curr = d[c.lower()]
                if (last and last != curr):
                    ret = False
                    #print last, curr
                    break
                else:
                    ret = True
                last = curr
                #print last
            #print s, ret
            if ret:
                retList.append(s)
        return retList

def stringToStringArray(input):
    return json.loads(input)

def stringArrayToString(input):
    return json.dumps(input)

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            words = stringToStringArray(line)
            
            ret = Solution().findWords(words)

            out = stringArrayToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()
