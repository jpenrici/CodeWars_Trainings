# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-

# CODEWARS
# https://www.codewars.com/kata/5583090cbe83f4fd8c000051
#
# "Convert number to reversed array of digits"


def digitize(n):

    if n == 0:
        return [0]
    if n < 0:
        n *= -1
    
    arr = []
    while n > 0:
        arr += [n % 10]
        n /= 10
    return arr

def testEqual(test, str1, str2):
    print(test, str1 == str2)

def main():
    testEqual(1, digitize(35231),[1,3,2,5,3])
    testEqual(2, digitize(348597),[7,9,5,8,4,3])
    testEqual(3, digitize(0),[0])
    testEqual(4, digitize(1),[1])
    testEqual(5, digitize(10),[0,1])
    testEqual(6, digitize(100),[0,0,1])
    testEqual(7, digitize(-1000),[0,0,0,1])

if __name__ == '__main__':
    main()