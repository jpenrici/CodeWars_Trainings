/*
CODEWARS
https://www.codewars.com/kata/559a28007caad2ac4e000083

"Perimeter of squares in a rectangle"
*/

#include <iostream>
#include <vector>

typedef unsigned long long ull;

class SumFct
{
public:
  static ull perimeter(int n);
};

// Solução
ull SumFct::perimeter(int n)
{
  if (n < 1)
    return (ull) 4 * n;

  n++;  // Adequar aos testes
  ull sum(4);
  std::vector<ull> fib {0, 1};
  for (int i = 2; i <= n; ++i)
  {
    fib.push_back(0);
    fib[i] = fib[i - 1] + fib[i - 2];
    sum += 4 * fib[i];
  }
  return sum;
}

// Testes
void testequal(ull ans, ull sol) {
  std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
  std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
  testequal(SumFct::perimeter(5), 80);
  testequal(SumFct::perimeter(7), 216);
  testequal(SumFct::perimeter(20), 114624);
  testequal(SumFct::perimeter(30), 14098308);

  return 0;
}

/*
Sample Tests:
typedef unsigned long long ull;
void testequal(ull ans, ull sol)
{
    Assert::That(ans, Equals(sol));
}
void testequal(int n, ull expected)
{
    testequal(SumFct::perimeter(n), expected);
}
Describe(perimeter_Tests)
{
    It(Fixed__Tests)
    {
      testequal(5, 80);
      testequal(7, 216);
      testequal(20, 114624);
      testequal(30, 14098308);
    }
};
*/