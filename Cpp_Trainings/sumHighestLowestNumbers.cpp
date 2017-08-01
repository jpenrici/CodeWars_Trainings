/*
CODEWARS
https://www.codewars.com/kata/576b93db1129fcf2200001e6

"Sum without highest and lowest number"

Description:

Sum all the numbers of the array (in F# and Haskell you get a list) except the
highest and the lowest element (the value, not the index!).
(The highest/lowest element is respectively only one element at each edge, even
if there are more than one with the same value!)

Example:
{ 6, 2, 1, 8, 10 } => 16
{ 1, 1, 11, 2, 3 } => 6


If array is empty, null or None, or if only 1 Element exists, return 0.
Note:In C++ instead null an empty vector is used. In C there is no null. ;-)
*/

#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> numbers)
{
	if (numbers.empty())
		return 0;
	if (numbers.size() == 1)
		return numbers[0];

	unsigned int posMax = 0;
	unsigned int posMin = 0;
	int sum = 0;

	for(unsigned int pos = 0; pos < numbers.size(); pos++){
		if (numbers[pos] >= numbers[posMax])
			posMax = pos;
		if (numbers[pos] <= numbers[posMin])
			posMin = pos;
	}

	for(unsigned int pos = 0; pos < numbers.size(); pos++){
		if (pos != posMin && pos != posMax)
			sum += numbers[pos];
	}

	return sum;
}

// Imprime Teste
void test(string s, vector<int> v)
{
	cout << s << " " << sum(v) << endl;
}

// Testes
int main()
{
	// -std=c++11
	vector<int> v;

	v = { 6, 2, 1, 8, 10 };
	test("{ 6, 2, 1, 8, 10 }", v);

	v =  { 1, 1, 11, 2, 3 };
	test("{ 1, 1, 11, 2, 3 }", v);

	v = {-1};
	test("{-1}", v);

	return 0;
}
