# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-

# CODEWARS
# https://www.codewars.com/kata/563b662a59afc2b5120000c6
# 
# "Growth of a Population"

def nb_year(p0, percent, aug, p):
    years = 0
    while p0 < p:
        p0 += p0 * (percent * 0.01) + aug
        years += 1
    return years

def testEqual(str1, str2):
    print(str1 == str2)

def main():
    testEqual(nb_year(1500, 5, 100, 5000), 15)
    testEqual(nb_year(1500000, 2.5, 10000, 2000000), 10)
    testEqual(nb_year(1500000, 0.25, 1000, 2000000), 94)

if __name__ == '__main__':
    main()