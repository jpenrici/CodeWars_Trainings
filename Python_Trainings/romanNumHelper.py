# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-

# CODEWARS
# http://www.codewars.com/kata/51b66044bce5799a7f000003
#
# "Roman Numerals Helper"

class RomanNumerals(object):

    symbol = {
        "M": 1000, "CM": 900, "D": 500, "CD": 400,
        "C": 100,  "XC": 90,  "L": 50,  "XL": 40,
        "X": 10,   "IX": 9,   "V": 5,   "IV": 4,
        "I": 1
    } 

    @classmethod
    def to_roman(self, num):
        roman = ""
        for s, n in \
            sorted(self.symbol.iteritems(), \
            key= lambda(k,v): (v,k), reverse = True):
                while (num >= n):
                    roman += s
                    num -= n
        return roman

    @classmethod
    def from_roman(self, roman):
        number = 0
        roman = roman.upper()
        while len(roman) > 0:
            if roman[:2] in self.symbol.keys():
                number += self.symbol[roman[:2]]
                roman = roman[2:]
            else:
                number += self.symbol[roman[:1]]
                roman = roman[1:]
        return number

def testEqual(test, value1, value2):
    print(test, value1 == value2)

def main():
    # Top Roman
    testEqual(1, RomanNumerals.to_roman(0), '')
    testEqual(2, RomanNumerals.to_roman(1000), 'M')
    testEqual(3, RomanNumerals.to_roman(1990), 'MCMXC')
    testEqual(4, RomanNumerals.to_roman(2008), 'MMVIII')
    testEqual(5, RomanNumerals.to_roman(1666), 'MDCLXVI')

    # From Roman
    testEqual(6, 0, RomanNumerals.from_roman(''))
    testEqual(7, 1000, RomanNumerals.from_roman('M'))
    testEqual(8, 1990, RomanNumerals.from_roman('MCMXC'))
    testEqual(9, 2008, RomanNumerals.from_roman('MMVIII'))
    testEqual(10, 1666, RomanNumerals.from_roman('mdclxvi'))

if __name__ == '__main__':
    main()