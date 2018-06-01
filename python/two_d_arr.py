#!/usr/bin/env python

def fun(a):
#print a
#print a[0]
#print a[0][0]
    for row in a:
        for item in row:
            i = 1
#print item

    for i in range(len(a)):
        for j in range(len(a[i])):
            print a[i][j]

def fun2(a):
    sum = 0
    for i in range(len(a)):
        sum += a[i][i]
    return sum

def rooks(a):
    for i in range(len(a)):
        sum = 0
        for j in range(len(a)):
            sum += a[i][j]
        if (sum > 1):
            return False

    for i in range(len(a)):
        sum = 0
        for j in range(len(a)):
            sum += a[j][i]
        if (sum > 1):
            return False

    return True

def main():
    a = [[1,2,3], [4,5,6], [7,8,9]]
    b = [[1,0,0], [0,1,0], [0,0,1]]
#fun(a)
#print fun2(a)
    print rooks(b)

if __name__ == '__main__':
     main()

