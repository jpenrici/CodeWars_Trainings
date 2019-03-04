/*
CODEWARS
https://www.codewars.com/kata/554e4a2f232cdd87d9000038

"Complementary DNA"
*/

#include <iostream>

std::string DNAStrand(std::string dna)
{
    for (int i = 0; i < dna.size(); ++i)
    {
        switch (dna[i])
        {
            case 'A': dna[i] = 'T'; break;
            case 'C': dna[i] = 'G'; break;
            case 'T': dna[i] = 'A'; break;
            case 'G': dna[i] = 'C'; break;
        }

    }
    return dna;
}

int main()
{
    std::cout << std::boolalpha << (DNAStrand("AAAA") == "TTTT") << std::endl;
    std::cout << std::boolalpha << (DNAStrand("ATTGC") == "TAACG") << std::endl;
    std::cout << std::boolalpha << (DNAStrand("GTAT") == "CATA") << std::endl;

    return 0;
};
