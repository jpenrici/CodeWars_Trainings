# -*- Mode: Python; coding: utf-8; indent-tabs-mpythoode: nil; tab-width: 4 -*-

# CODEWARS
# https://www.codewars.com/kata/554e4a2f232cdd87d9000038
# 
# "Complementary DNA"

def DNA_strand(dna):
    dna.upper()
    output = ""
    for c in dna:
        if c == 'A': output += 'T' 
        if c == 'C': output += 'G' 
        if c == 'T': output += 'A' 
        if c == 'G': output += 'C' 
    return output

def compare(num, str1, str2):
    test = len(str1) == len(str2) and str1 == str2
    print('[{0}]: {1}'.format(num, test))

def main():
    compare(1, "TTTT", DNA_strand("AAAA"))
    compare(2, "AAAA", DNA_strand("TTTT"))
    compare(3, "TAACG", DNA_strand("ATTGC"))
    compare(4, "ATTGC", DNA_strand("TAACG"))
    compare(5, "CATA", DNA_strand("GTAT"))
    compare(6, "GTAT", DNA_strand("CATA"))

if __name__ == '__main__':
    main()