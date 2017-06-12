/*
CODEWARS
https://www.codewars.com/kata/565c0fa6e3a7d39dee000125

"Braking well"

Braking distance d1 is the distance a vehicle will go from the point
when it brakes to when it comes to a complete stop. It depends on the
original speed v and on the coefficient of friction mu between the tires
and the road surface.

The braking distance is one of two principal components of the total
stopping distance. The other component is the reaction distance, which
is the product of the speed and the perception-reaction time of the
driver.

The kinetic energy E is 0.5*m*v**2, the work W given by braking is
mu*m*g*d1. Equalling E and W gives the braking distance:
d1 = v*v / 2*mu*g 
where g is the gravity of Earth and m the vehicle's mass.

We have v in km per hour, g as 9.81 m/s/s and in the following we
suppose that the reaction time is constant and equal to 1 s.
The coefficient mu is dimensionless.

There are two tasks.

  * The first one is to calculate the total stopping distance in meters
    given v, mu (and the reaction time t = 1).

		dist(v, mu) -> d = total stopping distance

  * The second task is to calculate v in km per hour knowing d in meters
    and mu with the supposition that the reaction time is still t = 1.

		speed(d, mu) -> v such that dist(v, mu) = d.

#Examples:

dist(100, 0.7) -> 83.9598760937531

speed(83.9598760937531, 0.7) -> 100.0

#Notes:

    * Remember to convert the velocity from km/h to m/s or from m/s
      in km/h when necessary.
    * Don't forget the reaction time t: t = 1
    * Don't truncate or round your results. See in "RUN EXAMPLES" the
      function assertFuzzyEquals.
    * Shell: only dist is tested.
*/

#include <iostream>
#include <iomanip>	// Teste
#include <cmath>	  // Solução

class Braking
{
public:
    static double dist(double v, double mu);
    static double speed(double d, double mu);
};

// Solução
double Braking::dist(double v, double mu)
{
	double d0, d1, d2, d, t, g;
	
	if (mu == 0)
		return 0;
	
	d0 = 0;		  // ponto de partida [m]
	t = 1;		  // tempo de reação (1 s)
	g = 9.81;	  // gravidade [m/s]
	v /= 3.60;	// Km/h -> m/s
	
	d1 = d0 + (v * t);	// Distância percorrida após 1 s
	d2 = pow(v, 2.0)/(2 * mu * g);	// Distância de parada
	d = d1 + d2;	// Distância percorrida
	
	return d;
}

double Braking::speed(double d, double mu)
{
	double v, t, a, g, d0;
	
	if (mu == 0)
		return 0;
	
	d0 = 0;
	t = 1;
	g = 9.81;
	a = 1/(2 * mu * g);
	
	// d = (d0 + v*t) + (v^2 / 2*mu*g);
	// (a * v^2) + (t * v) + d0 - d = 0
	v = (-t + sqrt( pow(t, 2) - 4 * a * (d0 - d) ) ) / (2 * a);	// [m/s]
	v *= 3.6;	// m/s -> Km/h
	
	return v;
}

// Teste
void assertFuzzyEquals(double act, double exp)
{
    bool inrange = std::abs(act - exp) <= 1e-6;
    if (inrange == false)
    {
        std::cout << std::setprecision(6);
        std::cout << "At 1e-6: Expected should be " << exp;
        std::cout << ", but got " << act << std::endl;
        std::cout << "Error!" << std::endl;
    } else {
		std::cout << "At 1e-6: Expected should be " << exp;
        std::cout << ", and got " << act << std::endl;
        std::cout << "OK!" << std::endl;
    }
}

static void dotest1(double v, double mu, double expected)
{
    assertFuzzyEquals(Braking::dist(v, mu), expected);
}

static void dotest2(double d, double mu, double expected)
{
    assertFuzzyEquals(Braking::speed(d, mu), expected);
}

// Testes
int main() {
	
	// Teste: dist_Tests
	dotest1(144, 0.3, 311.83146449201496);
	dotest1(92, 0.5, 92.12909477605366);
	
	// Teste: speed_Tests
	dotest2(159, 0.8, 153.79671564846308);
	dotest2(164, 0.7, 147.91115701756493);
	
	return 0;
};
