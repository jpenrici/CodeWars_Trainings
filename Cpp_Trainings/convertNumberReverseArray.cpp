/*
CODEWARS
https://www.codewars.com/kata/5583090cbe83f4fd8c000051

"Convert number to reversed array of digits"

Given a random number:
    C#: long;
    C++: unsigned long;

You have to return the digits of this number within an array in reverse
order.

Example:

348597 => [7,9,5,8,4,3]
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Solução
std::vector<int> digitalize(long long n)
{
	std::vector<int> vectorOut;
	
	if (n< 0)
		n *= -1;
		
	while ( n >= 10)
	{
		vectorOut.push_back(n % 10);
		n /= 10;
	}
	
	vectorOut.push_back(n);
	
	return vectorOut;
}

// Imprime Vetor
void printVector (std::vector<int> vetor){
	
	cout << "{ ";
	for (unsigned int i = 0; i < vetor.size() - 1; i++)
		cout << vetor[i] << ",";
	cout << vetor[vetor.size() - 1] << " }";	
}

// Teste
void test(long long n, std::vector<int> vExpected ){
	
	std::vector<int> vTest;
	vTest = digitalize(n);
	
	cout << n << "\t, ";
	printVector(vTest);
	cout << " => ";
	printVector(vExpected);
	
	if (vTest == vExpected)
		cout << " OK!";
	else
		cout << " Error!";
		
	cout << endl;
}

// Testes
int main()
{
	// Exemplo
	test(348597, std::vector<int>({ 7,9,5,8,4,3 }));
	
	// Teste básico
	test(35231 , std::vector<int>({ 1,3,2,5,3 }));
	
	// 1 dígito
	test(0 , std::vector<int>({ 0 }));
	test(1 , std::vector<int>({ 1 }));
	
	// 2 dígitos
	test(10 , std::vector<int>({ 0,1}));
	
	// 3 dígitos
	test(100 , std::vector<int>({ 0,0,1 }));
	
	// Número negativo
	test(-1000 , std::vector<int>({ 0,0,0,1 }));
	
	// Basic_tests
	long long n1 = 45762893920LL;
	test(n1, std::vector<int>({0,2,9,3,9,8,2,6,7,5,4}));
	
	return 0;
}
