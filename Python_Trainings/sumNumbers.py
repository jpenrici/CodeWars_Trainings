# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-

# CODEWARS
# https://www.codewars.com/kata/576b93db1129fcf2200001e6
#
# "Sum without highest and lowest number"


def sum_array(arr):
    if arr == None:
        return 0
    if len(arr) <= 2:
        return 0
    arr.sort()
    del arr[0]
    del arr[-1]
    return sum(arr)

def testEqual(test, str1, str2):
    print("[{0:d}]: {1}".format(test, str1 == str2))

def main():
    # "Basic tests"
    # "None or Empty"
    testEqual(1, sum_array(None), 0)
    testEqual(2, sum_array([]), 0)

    # "Only one Element"
    testEqual(3, sum_array([3]), 0)
    testEqual(4, sum_array([-3]), 0)

    # "Only two Element"
    testEqual(5, sum_array([ 3, 5]), 0)
    testEqual(6, sum_array([-3, -5]), 0)

    # "Real Tests"
    testEqual(7, sum_array([6, 2, 1, 8, 10]), 16)
    testEqual(8, sum_array([6, 0, 1, 10, 10]), 17)
    testEqual(9, sum_array([-6, -20, -1, -10, -12]), -28)
    testEqual(10, sum_array([-6, 20, -1, 10, -12]), 3)

if __name__ == '__main__':
    main()
