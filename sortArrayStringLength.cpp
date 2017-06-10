/*
CODEWARS
https://www.codewars.com/kata/57ea5b0b75ae11d1e800006c

"Sort array by string length"

Write a function that takes an array of strings as an argument and
returns a sorted array containing the same strings, ordered from
shortest to longest.

For example, if this array were passed as an argument:

["Telescopes", "Glasses", "Eyes", "Monocles"]

Your function would return the following array:

["Eyes", "Glasses", "Monocles", "Telescopes"]

All of the strings in the array passed to your function will be
different lengths, so you will not have to decide how to order
multiple strings of the same length.
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Solução
class Kata
{
public:
    std::vector<std::string> sortByLength(std::vector<std::string> array)
    {
	//unsigned int i, j; // retirado pra evitar erro SIGSEGV
	int i, j;
	std::string temp;
	for (i = array.size() - 1; i >= 1; i--)
		for (j = 0; j < i; j++)
			if (array[j].length() > array[j + 1].length()){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}	
        return array;
    }
};

// Imprime vetor
void printVector (std::vector<std::string> v){
	
	cout << "{ ";
	for (unsigned int i = 0; i < v.size() - 1; i++)
		cout << v[i] << ",";
	cout << v[v.size() - 1] << " }";	
}

// Imprime Teste
void teste(std::vector<std::string> vTest,
	std::vector<std::string> vExpected ){
	
    Kata kata;
    std::vector<std::string> actual = kata.sortByLength(vTest);
    
    cout << "Original: ";
    printVector(vTest);
    cout << endl;
    printVector(actual);
    cout << " = ";
    printVector(vExpected);
    
	if (actual == vExpected)
		cout << " True" << endl;
	else
		cout << " False" << endl;

	cout << endl;
}

// Testes
int main()
{
    // Teste inicial de igualdade
    teste({ "Beg", "Life", "I", "To" }, { "Beg", "Life", "I", "To" });
    
    // Testes
    teste({ "Beg", "Life", "I", "To" }, { "I", "To", "Beg", "Life" });
    teste({ "", "Moderately", "Brains", "Pizza" }, { "", "Pizza", "Brains", "Moderately" });
    teste({ "Longer", "Longest", "Short" }, { "Short", "Longer", "Longest" } );
    
    // Outros
    teste({"abcde", "abc", "", "abcd", "a"}, {"", "a", "abc", "abcd", "abcde"});
    
    return 0;
}
