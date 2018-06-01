#!/usr/bin/env python

def neg_count(a):
    sum = 0
    n = len(a)
    i = 0
    j = n - 1
    while (j >= 0 and i < n):
        if a[i][j] < 0:
            sum += j + 1
            i += 1
        else:
            j -= 1
    return sum

def main():
    b = [[-4,-3,0], [-1,0,0], [0,0,1]]
    print neg_count(b)

if __name__ == '__main__':
     main()

