/*
CODEWARS
https://www.codewars.com/kata/5544c7a5cb454edb3c000047

"Loading Kata: Bouncing Balls"
*/

#include <iostream>

using namespace std;

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};

// Solução
int Bouncingball::bouncingBall(double h, double bounce, double window)
{
	int count(1);
	if (h <= 0 || window >= h || bounce <= 0 || bounce >= 1)
		return -1;
	while (h > window)
	{
		h = h * bounce;
		if (h > window)
			count = count + 2;
	}
	return count;
}

// Testes
void testequal(int ans, int sol) {
  std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(Bouncingball::bouncingBall(3, 0.66, 1.5), 3);
    testequal(Bouncingball::bouncingBall(30, 0.66, 1.5), 15);
    testequal(Bouncingball::bouncingBall(10, 0.6, 10), -1);
}
