/*
CodeWars
https://www.codewars.com/kata/54c14c1b86b33df1ff000026

"Base -2"
*/

#include <iostream>
#include <string>
#include <cmath>

class Negabinary{
public:
  static std::string ToNegabinary(int value);
  static int ToInt(std::string binary);
};

std::string Negabinary::ToNegabinary(int value)
{
  if (value == 0) return "0";

  std::string binary ("");
  while(value != 0) {
      int remainder = value % -2;
      value /= -2;

      if (remainder < 0) {
        remainder += 2;
        value++;
      }
      binary = std::to_string(remainder) + binary;
  }
  return binary;
}

int Negabinary::ToInt(std::string binary)
{
  // Negabinary -> decimal
  int decimal(0);
  int bits = binary.size();
  for (int i = 0; i < bits; ++i) {
    decimal += (char(binary[bits - i - 1]) - '0') * pow(-2, i);
  }
  return decimal;
}

void testequal(int ans, int sol)
{
  std::cout << "\nans: " << ans << "\nsol: " << sol << "\n\t"
        << std::boolalpha << (ans == sol) << '\n';
}

void testequal(std::string ans, std::string sol)
{
  std::cout << "\nans: " << ans << "\nsol: " << sol << "\n\t"
        << std::boolalpha << (ans == sol) << '\n';
}

void test()
{
    // ToNegaBinaryTest
    testequal(Negabinary::ToNegabinary(6), "11010");
    testequal(Negabinary::ToNegabinary(-6), "1110");

    testequal(Negabinary::ToNegabinary(4),   "100");
    testequal(Negabinary::ToNegabinary(18),  "10110");
    testequal(Negabinary::ToNegabinary(-11), "110101");

    // ToIntTest
    testequal(Negabinary::ToInt("11010"), 6);
    testequal(Negabinary::ToInt("1110"), -6);
}

int main()
{
  test();
  return 0;
}

/*
DESCRIPTION:

In this Kata you must convert integers numbers from and to a negative-base binary system.

Negative-base systems can accommodate all the same numbers as standard place-value systems,
but both positive and negative numbers are represented without the use of a minus sign
(or, in computer representation, a sign bit); this advantage is countered by an increased
complexity of arithmetic operations.

To help understand, the first eight digits (in decimalimal) of the Base(-2) system is:

[1, -2, 4, -8, 16, -32, 64, -128]

Example conversions:

Decimal, negabinary

6,   '11010'
-6,  '1110'
4,   '100'
18,  '10110'
-11, '110101'
*/
