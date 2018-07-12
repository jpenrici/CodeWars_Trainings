# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-

# CODEWARS
# https://www.codewars.com/kata/555eded1ad94b00403000071
# 
# "Sum of the first nth term of Series"

def series_sum(n):
    if n == 0: return "0.00"
    sum = 0.00
    for i in range(n):
        sum += 1.0 / (1.0 + i + (2.0 * i))
    return "{0:.2f}".format(sum)

def testEqual(str1, str2):
    print(str1 == str2)

def main():
    testEqual(series_sum(1), "1.00")
    testEqual(series_sum(2), "1.25")
    testEqual(series_sum(3), "1.39")

if __name__ == '__main__':
    main()