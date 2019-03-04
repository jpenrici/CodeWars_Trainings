*
CODEWARS
https://www.codewars.com/kata/565abd876ed46506d600000d

"Simpson's Rule - Approximate Integration"
*/

#include <iostream>
#include <iomanip>
#include <cmath>

class SimpsonIntegration
{
public:
    static double simpson(int n);
    static double function(double x);
};

// Solução
double SimpsonIntegration::function(double x){
	double y;
	y = 1.50 * pow(sin(x), 3);  // y = f(x)
	return y;
}

double SimpsonIntegration::simpson(int n)
{
	double temp, sum, sol, a, b, h;
	
	a = 0;			    // [0, Pi]
	b = 3.14159265;	// PI
	h = (b - a) / double(n);
	
	sol = (b - a) / (3 * double(n));
	sum = 0;
	temp = function(a) + function(b);
	
	for (int i = 1; i <= (n/2); i++)
	{
		sum += function(a + (2 * i - 1) * h);
	}
	
	temp += 4 * sum;
	sum = 0;
	
	for (int i = 1; i <= (n/2 - 1) ; i++)
	{
		sum += function(a + 2 * i * h);
	}
	
	temp += 2 * sum;
	sol *= temp;
	
	return sol;
}

// Testes
void assertFuzzyEquals(double act, double exp)
{
    bool inrange = std::abs(act - exp) <= 1e-10;
    if (inrange == false)
    {
        std::cout << std::setprecision(10);
        std::cout << "At 1e-10: Expected should be " << exp;
        std::cout << ", but got " << act << " Error!" << std::endl;
    } else {
        std::cout << std::setprecision(10);
        std::cout << "At 1e-10: Expected should be " << exp;
        std::cout << ", and got " << act << " Ok!" << std::endl;
    }
}

void dotest(int n, double expected)
{
    assertFuzzyEquals(SimpsonIntegration::simpson(n), expected);
}

int main() 
{
	dotest(290, 1.9999999986);
	dotest(72, 1.9999996367);
	dotest(252, 1.9999999975);
	dotest(40, 1.9999961668);
    
    return 0;
}
