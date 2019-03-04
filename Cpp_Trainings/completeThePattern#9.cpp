/*
CODEWARS
https://www.codewars.com/kata/5579e6a5256bac65e4000060

"Complete The Pattern #9 - Diamond"
*/

#include <iostream>
#include <sstream>

// Solução
// Sequência de números na linha
std::string sequence(int line, int n)
{
	std::stringstream buffer;
	std::string temp, space, left, center, rigth;

  for (int i = 0; i < n - line; ++i)
  {
      space = space + char(32);
  }
  for (int i = 1; i < line; ++i)
  {
    buffer << i;
    temp = buffer.str();
		left = left + temp[temp.length() - 1];
		rigth = temp[temp.length() - 1] + rigth;
    buffer.str("");
	 }
   buffer << line;
   temp = buffer.str();
	 center = temp[temp.length() - 1];
	 return space + left + center + rigth + space;
}

// Padronizar - Diamante
std::string pattern(int n)
{
	std::string temp, top, center, bottom;

    if (n <= 0)
        return "";
    if (n == 1)
        return "1";

	for (int i = 1; i < n; ++i)
	{
		temp = sequence(i,n);
		top = top + temp + "\n";
		bottom = temp + bottom;
    if (i < n - 1)
      bottom = "\n" + bottom;
	}
	center = sequence(n,n) + "\n";
  return top + center + bottom;
}

// Testes
void testequal(std::string actual, std::string expected) {
  std::cout << "actual) " << actual << "\nexpected) " << expected << "\nactual = expected: " ;
	std::cout << std::boolalpha << (actual == expected) << std::endl;
}

int main()
{
   std::string expected = "      1      \n     121     \n    12321    \n   1234321   \n  123454321  \n 12345654321 \n1234567654321\n 12345654321 \n  123454321  \n   1234321   \n    12321    \n     121     \n      1      ";
   std::string actual = pattern(7);
   testequal("\n" + actual, "\n" + expected);

   expected = "1";
   actual = pattern(1);
   testequal("\n" + actual, "\n" + expected);

   expected = "  1  \n 121 \n12321\n 121 \n  1  ";
   actual = pattern(3);
   testequal("\n" + actual, "\n" + expected);

   expected = "";
   actual = pattern(0);
   testequal("\n" + actual, "\n" + expected);

   expected = "";
   actual = pattern(-25);
   testequal("\n" + actual, "\n" + expected);

   std::cout << pattern(14) << std::endl;
   std::cout << pattern(28) << std::endl;

   return 0;
}
