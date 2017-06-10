/*
CODEWARS
https://www.codewars.com/kata/54b724efac3d5402db00065e

"Decode the Morse code"

Part of Series 1/3

This kata is part of a series on the Morse code.
After you solve this kata, you may move to the next one.

In this kata you have to write a simple Morse code decoder.
While the Morse code is now mostly superceded by voice and digital data
communication channels, it still has its use in some applications around
the world.

The Morse code encodes every character as a sequence of "dots" and
"dashes". For example, the letter A is coded as ·−, letter Q is coded as
−−·−, and digit 1 is coded as ·−−−. The Morse code is case-insensitive,
traditionally capital letters are used. When the message is written in
Morse code, a single space is used to separate the character codes and 3
spaces are used to separate words. For example, the message HEY JUDE in
Morse code is ···· · −·−− ·−−− ··− −·· ·.

NOTE: Extra spaces before or after the code have no meaning and should
be ignored.

In addition to letters, digits and some punctuation, there are some
special service codes, the most notorious of those is the international
distress signal SOS (that was first issued by Titanic), that is coded as
···−−−···. These special codes are treated as single special characters,
and usually are transmitted as separate words.

Your task is to implement a function decodeMorse(morseCode), that would
take the morse code as input and return a decoded human-readable string.

For example:

decodeMorse('.... . -.--   .--- ..- -.. .')
//should return "HEY JUDE"

The Morse code table is preloaded for you as a dictionary, feel free to
use it. In CoffeeScript, C++, JavaScript, PHP, Python, Ruby and
TypeScript, the table can be accessed like this: MORSE_CODE['.--'], in
Java it is MorseCode.get('.--'), in C# it is MorseCode.Get('.--'), in
Haskell the codes are in a Map String String and can be accessed like
this: morseCodes ! ".--", in Elixir it is morse_codes variable.

All the test strings would contain valid Morse code, so you may skip
checking for errors and exceptions. In C#, tests will fail if the
solution code throws an exception, please keep that in mind. This is
mostly because otherwise the engine would simply ignore the tests,
resulting in a "valid" solution.

Good luck!
*/

#include <iostream>
#include <map>

// MAP
char findCode(std::string sequence) {

	char value = ' ';
	
	std::map <std::string, char> MORSE_CODE;
	MORSE_CODE[".-"] = 'A';
	MORSE_CODE["-..."] = 'B';
	MORSE_CODE["-.-."] = 'C';
	MORSE_CODE["-.."] = 'D';
	MORSE_CODE["."] = 'E';
	MORSE_CODE["..-."] = 'F';
	MORSE_CODE["--."] = 'G';
	MORSE_CODE["...."] = 'H';
	MORSE_CODE[".."] = 'I';
	MORSE_CODE[".---"] = 'J';
	MORSE_CODE["-.-"] = 'K';
	MORSE_CODE[".-.."] = 'L';
	MORSE_CODE["--"] = 'M';
	MORSE_CODE["-."] = 'N';	
	MORSE_CODE["---"] = 'O';
	MORSE_CODE[".--."] = 'P';
	MORSE_CODE["--.-"] = 'Q';
	MORSE_CODE[".-."] = 'R';
	MORSE_CODE["..."] = 'S';
	MORSE_CODE["-"] = 'T';
	MORSE_CODE["..-"] = 'U';
	MORSE_CODE["...-"] = 'V';
	MORSE_CODE[".--"] = 'W';
	MORSE_CODE["-..-"] = 'X';
	MORSE_CODE["-.--"] = 'Y';
	MORSE_CODE["--.."] = 'Z';
	MORSE_CODE[".----"] = '1';
	MORSE_CODE["..---"] = '2';
	MORSE_CODE["...--"] = '3';
	MORSE_CODE["....-"] = '4';
	MORSE_CODE["....."] = '5';
	MORSE_CODE["-...."] = '6';
	MORSE_CODE["--..."] = '7';
	MORSE_CODE["---.."] = '8';
	MORSE_CODE["----."] = '9';
	MORSE_CODE["-----"] = '0';
	
	for (std::map<std::string, char>::iterator p = MORSE_CODE.begin( );
      p != MORSE_CODE.end( ); ++p ) {
		  if (p->first == sequence)
			value = p->second;
   }
	return value;
}

// Solução
std::string decodeMorse(std::string morseCode) {
	
	std::string decoded, aux;
	int pos, size, spaces;
	
	pos = 0;
	size = morseCode.length();
	
	// Retirar espaços no início
	while (morseCode[pos] == char(32) && pos < size)
		pos++;
		
	// Retirar espaços no final
	while (morseCode[size - 1] == char(32) && size > 0)
		size--;
	
	// Decodificar
	while (pos < size) {
		
		aux = "";
		spaces = 0;
		
		// Testar sequência de espaços
		while (morseCode[pos] == char(32) && pos < size){
			std::cout << "^";
			spaces++;
			if (spaces == 3) {
				decoded += char(32);
				//spaces = 0;
			}
			pos++;
		}
		
		// Testar [.-]
		while (morseCode[pos] != char(32) && pos < size) {
			std::cout << morseCode[pos];
			aux += morseCode[pos];
			pos++;
		}

		// Cógidos Extras para Teste
		if (aux == "...---...") {
				decoded += "SOS";
				aux = "";
		}
		
		if (aux == ".-.-.-") {
				decoded += ".";
				aux = "";
		}
		
		if (aux == "-.-.--") {
				decoded += "!";
				aux = "";
		}
		
		// Traduzir sequência
		if (aux != "")
			decoded += findCode(aux);		// Teste
			//decoded += MORSE_CODE[aux]	// Plataforma
	}

	std::cout << "\n{" << decoded << "}";
    return decoded;
}

// Comparação
void test(std::string code, std::string text)
{
	std::cout << "{" << text << "}" << std::endl;
	
	if (decodeMorse(code) == text)
		std::cout << "\tOK!" << std::endl;
	else
		std::cout << "\tErro!" << std::endl;
}

// Testes
int main()
{
	
	// Example_from_Description
	test(".... . -.--   .--- ..- -.. .", "HEY JUDE");
	
	// Basic_Mode_decoding
	test(".-","A");
	test(".","E");
	test("..","I");
	test(". .","EE");
	test("...---...","SOS");
	test("... --- ...","SOS");
	test("...   ---   ...","S O S");

	// Extra_zeros_handling
	test(".", "E");
	test("   .   . ", "E E");
	
	// Complex_tests
	test("      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-     ","SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.");
	
	// Outros Testes
	test(".---- ..--- ...-- ....- ..... -.... --... ---.. ----.", "123456789");
	test(".- -...   -.-. -..   . ..-.   --. ....", "AB CD EF GH");
	test(".. .--- -.- .-.. -- -. --- .--. --.- .-.", "IJKLMNOPQR");
	test("... - ..-   ...- -..-   -.-- .-- --..", "STU VX YWZ");
	
	return 0;
}
