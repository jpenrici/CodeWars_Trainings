/*
CODEWARS
https://www.codewars.com/kata/565abd876ed46506d600000d

"Simpson's Rule - Approximate Integration"
*/
using System;

public class SimpsonIntegration 
{
    public static double Simpson(int n) 
    {
        double temp, sum, sol, a, b, h;
        
        a = 0;
        b = Math.PI;
        h = (b - a) / (double)n;
        
        sol = (b - a) / (3 * (double)n);
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

    public static double function(double x)
    {
        double y;
        y = 1.50 * Math.Pow(Math.Sin(x), 3);
        return y;
    }
}

public static class SimpsonIntegrationTests {

    private static void assertFuzzyEquals(double act, double exp)
    {
        bool inrange = Math.Abs(act - exp) <= 1e-10;
        if (inrange == false) 
        {
            string specifier = "#.0000000000";
            Console.WriteLine(
                "At 1e-10: Expected must be " + exp.ToString(specifier) + 
                ", but got " + act.ToString(specifier));
        }
        else
        {
            Console.WriteLine("test ok!");
        }
    }

    public static void test1() 
    {
        Console.WriteLine("Fixed Tests: Simpson"); 
        assertFuzzyEquals(SimpsonIntegration.Simpson(290), 1.9999999986);
        assertFuzzyEquals(SimpsonIntegration.Simpson(72), 1.9999996367);
        assertFuzzyEquals(SimpsonIntegration.Simpson(252), 1.9999999975);
        assertFuzzyEquals(SimpsonIntegration.Simpson(40), 1.9999961668);
    }

    static void Main(string[] args)
    {
        test1();            
        Console.ReadKey();
    }
}