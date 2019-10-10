#!/usr/bin/env python

def neg_count(a):
    sum = 0
    n = len(a)
    row_idx = 0
    col_idx = n - 1
    while (col_idx >= 0 and row_idx < n):
        if a[row_idx][col_idx] < 0:
            sum += col_idx + 1
            row_idx += 1
        else:
            col_idx -= 1
    return sum

def main():
    b = [[-4,-3,0], [-1,0,0], [0,0,1]]
    print neg_count(b)

if __name__ == '__main__':
     main()

