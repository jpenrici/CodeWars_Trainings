/*
CODEWARS
https://www.codewars.com/kata/562e274ceca15ca6e70000d3

"Parabolic Arc Length"

We want to approximate the length of a curve representing a function
y = f(x) with a<= x <= b. First, we split the interval [a, b] into
n sub-intervals with widths h1, h2, ... , hn 
by defining points x1, x2 , ... , xn-1 between a and b.
This defines points P0, P1, P2, ... , Pn on the curve whose
x-coordinates are a, x1, x2 , ... , xn-1, b and
y-coordinates f(a), f(x1), ..., f(xn-1), f(b) . 

By connecting these points, we obtain a polygonal path approximating
the curve.

Our task is to approximate the length of a parabolic arc representing
the curve y = x * x with x in the interval [0, 1]. 
We will take a common step h between the points 
xi: h1, h2, ... , hn = h = 1/n and 
we will consider the points P0, P1, P2, ... , Pn on the curve. 
The coordinates of each Pi are (xi, yi = xi * xi).

The function len_curve (or similar in other languages) takes
n as parameter (number of sub-intervals) and returns the length
of the curve truncated to 9 decimal places.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

class ArcParabLen
{
public:
    static double lenCurve(int n);
};

// Solução
double ArcParabLen::lenCurve (int n){
	
	double l(0), x0(0), x1(0), y0(0), y1(0), h;
	
	h = 1 / (double) n;
	
	for(int i = 0; i < n; i++) {
		
		// Ponto Inicial
		x0 = i * h;
		y0 = pow(x0, 2);
		std::cout <<  "P" << i << " (" << x0 << " , " << y0 << ")\t";

		// Ponto Final
		x1 = x0 + h;
		y1 = pow(x1, 2);
		std::cout <<  "P" << i << " (" << x1 << " , " << y1 << ")\t";
		
		// Segmento 
		l += sqrt ( pow((y1 - y0), 2) + pow(h, 2));
		std::cout <<  "l = " << l << std::endl;
	}
	 
	return l;
}

// Testes
void assertFuzzyEquals(double act, double exp)
{
    bool inrange = std::abs(act - exp) <= 1e-6;
    if (inrange == false)
    {
        std::cout << std::setprecision(6);
        std::cout << "At 1e-6: Expected should be " << exp;
        std::cout << ", but got " << act;
        std::cout << " Error!" << std::endl;
    } else
    {
        std::cout << std::setprecision(6);
        std::cout << "At 1e-6: Expected should be " << exp;
        std::cout << ", and got " << act;
        std::cout << " OK!" << std::endl;
    }    
    
}

void dotest(int nb, double expected)
{
    assertFuzzyEquals(ArcParabLen::lenCurve(nb), expected);
}

int main()
{

	dotest(1, 1.414213562);
	dotest(10, 1.478197397);

	return 0;
}
