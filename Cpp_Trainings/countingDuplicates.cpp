/*
CODEWARS
https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1

"Counting Duplicates"
*/

#include <iostream>

//size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
	int n(0), size;
	std::string s;
	char c, lastDuplicate;

	s = in;
	if (s == "")
		return n;
	size = s.size();
	std::cout << s << std::endl;

	// Maiúsculo para minúsculo
	for (int i = 0; i < size; ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	}

	// Ordenar string
	for (int i = size - 1; i >= 1; i--)
		for (int j = 0; j < i; ++j)
		{
			if (s[j] > s[j + 1])
			{
				c = s[j];
				s[j] = s[j + 1];
				s[j + 1] = c;
			}
		}

	// Contar Duplicatas
	lastDuplicate = char(0);
	for (int i = 0; i < size - 1; ++i)
	{
		if (s[i] != lastDuplicate && s[i] == s[i + 1])
		{
			lastDuplicate = s[i];
			n++;
		}
	}

    return n;
}

// Testes
void testequal(int ans, int sol) {
  std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(duplicateCount(" "), 0);
    testequal(duplicateCount(""), 0);
    testequal(duplicateCount("asdfghjkl;'\\"), 0);
    testequal(duplicateCount("asdfghjkl;'\\'"), 1);
    testequal(duplicateCount("aabbcde"), 2);
    testequal(duplicateCount("aabBcde"), 2);
    testequal(duplicateCount("Indivisibility"), 1);
    testequal(duplicateCount("Indivisibilities"), 2);
    testequal(duplicateCount("abcdefghijklmnopqrstuvwxyzbaaAAB"), 2);
    testequal(duplicateCount("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"), 26);

    return 0;
}
