/*
CODEWARS
https://www.codewars.com/kata/577b9960df78c19bca00007e

"Find n'th Digit of a Number"

The function findDigit takes two numbers as input, num and nth.
It outputs the nth digit of num (counting from right to left).

Note

    If num is negative, ignore its sign and treat it as a positive value.
    If nth is not positive, return -1.
    Keep in mind that 42 = 00042.
    This means that findDigit(42, 5) would return 0.

Examples

findDigit(5673, 4)     returns 5
findDigit(129, 2)      returns 2
findDigit(-2825, 3)    returns 8
findDigit(-456, 4)     returns 0
findDigit(0, 20)       returns 0
findDigit(65, 0)       returns -1
findDigit(24, -8)      returns -1
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Solução
int findDigit(int num, int nth){

	stringstream digits;

	if (num < 0) num *= -1;
	if (nth <= 0) return -1;

	digits << num;
	string s = digits.str();
	int t = s.size();

	if (nth > t) return 0;

	return (s[t - nth] - '0');
}

// Imprime Teste
void test(int num, int nth, int expected){
	cout << num << "\t";
	cout << findDigit(num, nth) << " => " << expected << endl;
}

// Testes
int main(){

	test(5673, 4, 5);
	test(129, 2, 2);
	test(-2825, 3, 8);
	test(-456, 4, 0);
	test(0, 20, 0);
	test(65, 0, -1);
	test(24, -8 ,-1);

	return 0;
}
