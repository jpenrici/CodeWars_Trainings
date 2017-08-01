/*
CODEWARS
https://www.codewars.com/kata/559536379512a64472000053

"Playing with passphrases"

Everyone knows passphrases. One can choose passphrases from poems, 
songs, movies names and so on but frequently they can be guessed due to
common cultural references. You can get your passphrases stronger by
different means. One is the following:

choose a text in capital letters including or not digits and
non alphabetic characters,

    1. shift each letter by a given number but the transformed letter 
       must be a letter (circular shift),
    2. replace each digit by its complement to 9,
    3. keep such as non alphabetic and non digit characters,
    4. downcase each letter in odd position, upcase each letter in even
       position (the first character is in position 0),
    5. reverse the whole result.

#Example:
your text: "BORN IN 2015!", shift 1

1 + 2 + 3 -> "CPSO JO 7984!"
4 "CpSo jO 7984!"
5 "!4897 Oj oSpC"

With longer passphrases it's better to have a small and easy program.
Would you write it?

https://en.wikipedia.org/wiki/Passphrase
*/

#include <iostream>
#include <string>

class PlayPass
{
  public:
	static std::string playPass(const std::string &s, int n);
};

// Solução
std::string PlayPass::playPass(const std::string &s, int n)
{
	std::string phrase = s;
	std::string aux = "";
	int size = phrase.length();
	int ascii;
	
	for(int i = 0; i < size; i++) {
		
		ascii = int(s[i]);
		
		// Alterar caixa [alta/baixa]
		if (ascii >= 65 && ascii <= 90) {		// [A - Z]
			if (i % 2 != 0) ascii += 32;		// [a - z]
		} else
			if (ascii >= 97 && ascii <= 122) {	// [a - z]
				if (i % 2 != 0)  ascii -= 32;	// [A - Z]
			}

		// Alterar alfabeto em N posições
		if (ascii >= 65 && ascii <= 90) {
			ascii += n;
			if (ascii > 90)
				ascii = ascii - 90 + 64;
			}
		if (ascii >= 97 && ascii <= 122) {
			ascii += n;
			if (ascii > 122)
				ascii = ascii - 122 + 96;
			}
			
		// Complemento a 9
		if (ascii > 47 && ascii < 58)  // [0 - 9]
			ascii = 105 - ascii;

		phrase[i] = char(ascii);

	}
	
	// Inverter String
	aux = phrase;
	for(int i = 0; i < size; i++){
		phrase[i] = aux[(size - 1) - i];
	}
	
	return phrase;
};

// Imprimir teste
void test(std::string o, int n, std::string e)
{

	std::string r = PlayPass::playPass(o, n);
	
	std::cout << o << "\n" << r << "\n" << e;
	
	if (r == e)
		std::cout << "\tOK!" << std::endl;
	else
		std::cout << "\tError!" << std::endl;
}

// Testes
int main()
{
	test("I LOVE YOU!!!", 1, "!!!vPz fWpM J");
        test("I LOVE YOU!!!", 0, "!!!uOy eVoL I");
        test("AAABBCCY", 1, "zDdCcBbB");
        test("MY GRANMA CAME FROM NY ON THE 23RD OF APRIL 2015", 2,
               "4897 NkTrC Hq fT67 GjV Pq aP OqTh gOcE CoPcTi aO");
        test("BORN IN 2015!", 1, "!4897 Oj oSpC");
         
	return 0;
}
