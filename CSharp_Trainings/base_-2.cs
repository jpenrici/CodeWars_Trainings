/*
CodeWars
https://www.codewars.com/kata/54c14c1b86b33df1ff000026

"Base -2"
*/

using System;

public static class Negabinary
{
    public static string ToNegabinary(int value)
    {
        if (value == 0)
            return "0";

        string binary = "";
        while(value != 0) {
            int remainder = value % -2;
            value /= -2;

            if (remainder < 0) {
                remainder += 2;
                value++;
            }
            binary = remainder.ToString() + binary;
        }

        return binary;
    }
    
    public static int ToInt(string binary)
    {
        // Negabinary -> decimal
        int number = 0;
        int bits = binary.Length;

        for (int i = 0; i < bits; ++i)
        {
            number += ((char)binary[bits - i - 1] - '0') * (int)Math.Pow(-2, i);
        }

        return number;
    }
}

public class Tests
{

    public static void ToNegabinaryTest()
    {
        AreEqual("11010", Negabinary.ToNegabinary(6));
        AreEqual("1110", Negabinary.ToNegabinary(-6));
    }

    public static void ToIntTest()
    {
        AreEqual(6, Negabinary.ToInt("11010"));
        AreEqual(-6, Negabinary.ToInt("1110"));
    }

    public static void AreEqual(int ans, int sol)
    {
        Console.WriteLine("Test: {0}", (ans == sol));
    }

    public static void AreEqual(string ans, string sol)
    {
        Console.WriteLine("Test: {0}", ans.Equals(sol));
    }

    public static void Main(string[] args)
    {

        ToNegabinaryTest();
        ToIntTest();

        Console.Write("Press enter to exit...");
        Console.ReadKey();
    }
}