/*
CODEWARS
https://www.codewars.com/kata/555eded1ad94b00403000071

"Sum of the first nth term of Series"

Task:
Your task is to write a function which returns the sum of following
series upto nth term(parameter).

Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...

Rules:
You need to round the answer upto 2 decimal places and return it as String.
If the given value is 0 then it should return 0.00
You will only be given Natural Numbers as arguments.

Examples:
SeriesSum(1) => 1 = "1"
SeriesSum(2) => 1 + 1/4 = "1.25"
SeriesSum(5) => 1 + 1/4 + 1/7 + 1/10 + 1/13 = "1.57"
*/

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Solução
string seriesSum(int n){
	ostringstream buffer;
	string s;
	float sum = 0;
	unsigned int point = 0;

	if (n == 0)
		return "0.00";

	for (int i = 0; i < n; i++)
		sum += 1 / float(1 + i + (2 * i));

	buffer << floor((sum * 100) + 0.5) / 100;
	s = buffer.str();

	for (unsigned int i = 0; i < s.size(); i++){
		if (s[i] == '.')
			point = i;
	}
  
	if (point != 0){
		if ((point + 1) <= s.size())
			s = s.substr(0, point + 3);
		if ((point + 2) <= s.size())
			s = s.substr(0, point + 4);
	}
	return s;
}

// Imprime Teste
void test (string expected, int n){
	cout << expected << " : " << seriesSum(n) << endl;
}

// Testes
int main(){
	test ("0.00", 0);
	test ("1.25", 2);
	test ("1.57", 5);
	test ("1.77", 9);
  
  return 0;
}
