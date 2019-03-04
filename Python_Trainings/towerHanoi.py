# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-
# CODEWARS
# https://www.codewars.com/kata/5899f1df27926b7d000000eb
#
# "Tower of Hanoi"

def tower_of_hanoi(rings):
    # Movimentos do Disco = (2^n) -1, n = número de discos.
    return (2**rings) - 1

def testEqual(number1, number2):
    print(number1 == number2)

def main():
    print("Basic tests")
    testEqual(tower_of_hanoi(4),15)
    testEqual(tower_of_hanoi(5),31)
    testEqual(tower_of_hanoi(10),1023)
    testEqual(tower_of_hanoi(50),1125899906842623)

if __name__ == '__main__':
    main()