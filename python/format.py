#!/usr/bin/env python

def main():
    print("%s\t%s\t%s" % ( 'a', 'a^2', 'a^3'))
    for x in range(1,6):
        print("%d\t%d\t%d" % ( x, x*x, x*x*x))

if __name__ == '__main__':
     main()

