/*
CODEWARS
https://www.codewars.com/kata/56747fd5cb988479af000028

"Get the Middle Character"
 
You are going to be given a word. Your job is to return the middle character of
the word. If the word's length is odd, return the middle character. If the
word's length is even, return the middle 2 characters.

Examples:

Kata.getMiddle("test") should return "es"
Kata.getMiddle("testing") should return "t"
Kata.getMiddle("middle") should return "dd"
Kata.getMiddle("A") should return "A"

Input
A word (string) of length 0 < str < 1000
Output
The middle character(s) of the word represented as a string.
*/

#include <iostream>
using namespace std;

// Solução
std::string get_middle(std::string input)
{
	// Retorna os caracteres do meio
	int c = input.length();
	if (c > 1000) return "";
	if (c <= 2) return input;

	string middle;

	if (c % 2 == 0)
		middle = input.substr((c/2) - 1, 2);
	else
		middle = input[c/2];

	return middle;
}

// Imprime Teste
void test (string s, string e, string r){
	cout << s << " : " << e << " = " << r << endl;
}

// Testes
int main(){

	test("12", "12", get_middle("12"));
	test("test", "es", get_middle("test"));
	test("testing", "t", get_middle("testing"));
	test("middle", "dd", get_middle("middle"));
	test("A", "A", get_middle("A"));

	return 0;
}
