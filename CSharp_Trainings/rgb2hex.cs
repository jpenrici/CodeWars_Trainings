/*
CODEWARS
https://www.codewars.com/kata/513e08acc600c94f01000001

"RGB To Hex Conversion"
*/
using System;

public class Kata
{
    public static string Rgb(int r, int g, int b) 
    {
        if (r < 0) r = 0;
        if (g < 0) g = 0;
        if (b < 0) b = 0;
        if (r > 255) r = 255;
        if (g > 255) g = 255;
        if (b > 255) b = 255;

        return (r.ToString("X2") + g.ToString("X2") + b.ToString("X2"));
    }
}

public class KataTests 
{
    private static void FixedTests()
    {
        testEqual("FFFFFF", Kata.Rgb(255,255,255));
        testEqual("FFFFFF", Kata.Rgb(255,255,300));
        testEqual("000000", Kata.Rgb(0,0,0));
        testEqual("9400D3", Kata.Rgb(148,0,211));
        testEqual("9400D3", Kata.Rgb(148,-20,211)); // Handle negative numbers.
        testEqual("90C3D4", Kata.Rgb(144,195,212));
        testEqual("D4350C", Kata.Rgb(212,53,12));   // Consider single hex digit numbers.
    }

    private static void testEqual(string ans, string sol)
    {
        Console.WriteLine("Test: {0}", ans.Equals(sol));
    }

    static void Main(string[] args)
    {
        FixedTests();

        // Console.ReadKey();
    }
}