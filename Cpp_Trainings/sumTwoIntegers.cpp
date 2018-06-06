/*
CodeWars
https://www.codewars.com/kata/5a9c35e9ba1bb5c54a0001ac

"Sum of Two Integers"
*/

#include <iostream>

// Given Two intgers a,b , find The sum of them,
// BUT You are not allowed to use the operators + and -
int Add (int x, int y)
{
	if (y == 0) return x;
	return Add(x^y, (x&y) << 1);
}

void testequal(size_t line, int ans, int sol)
{
	std::cout << "Line [" << line << "]: ";
	std::cout << std::boolalpha << (ans == sol) << '\n';
}

void test() 
{
	// Basic
	testequal(__LINE__, Add(0,0),    0);
	testequal(__LINE__, Add(1,0),    1);
	testequal(__LINE__, Add(0,1),    1);
	testequal(__LINE__, Add(-1,1),   0);
	testequal(__LINE__, Add(1,-1),   0);
	testequal(__LINE__, Add(-1,-1), -2);

	// Check_Positive_Values
	testequal(__LINE__, Add(1,2),    3);
	testequal(__LINE__, Add(5,19),  24);
	testequal(__LINE__, Add(23,17), 40);

	// Check_Negative_Values
	testequal(__LINE__, Add(-14,-16),   -30);
	testequal(__LINE__, Add(-50,-176), -226);
	testequal(__LINE__, Add(-10,-29),   -39);

	// Check_Mixture_Values
	testequal(__LINE__, Add(-13,13),   0);
	testequal(__LINE__, Add(-27,18),  -9);
	testequal(__LINE__, Add(-90,30), -60);
}

int main()
{
	test();
	return 0;
}
