/*
CODEWARS
https://www.codewars.com/kata/576b93db1129fcf2200001e6

"Sum without highest and lowest number"
*/

using System;
using System.Linq;
using System.Collections.Generic;

public static class Kata
{
    public static int Sum(int[] numbers)
    {
        if (numbers == null) return 0;
        if (numbers.Length <= 2) return 0;

        List<int> arr = new List<int> (numbers.Length);
        arr.AddRange(numbers);
        arr.Sort();
        int sum = 0;
        for (int i = 1; i < arr.Count - 1; ++i)
        {
            sum += arr[i];
        }
        return sum;
    }
}

public class SumTests
{

    public static void TestSumPositives(int num1, int num2)
    {
        Console.WriteLine(num1.Equals(num2));
    }

    static void Main(string[] args)
    {
        TestSumPositives(16, Kata.Sum(new[] { 6, 2, 1, 8, 10}));
        TestSumPositives(3, Kata.Sum(new[] { -6, 20, -1, 10, -12}));

        // Console.ReadKey();
    }
}