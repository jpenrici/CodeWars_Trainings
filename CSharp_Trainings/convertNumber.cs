/*
CODEWARS
https://www.codewars.com/kata/5583090cbe83f4fd8c000051

"Convert number to reversed array of digits"
*/

using System;
using System.Collections.Generic;

namespace Solution
{
  class Digitizer
  {
    public static long[] Digitize(long n)
    {
      List<long> vectorOut = new List<long>();
      
      if (n< 0) n *= -1;
      while ( n >= 10) {
        vectorOut.Add(n % 10);
        n /= 10;
      }
      vectorOut.Add(n);

      long[] output = vectorOut.ToArray();

      return output;
    }
  }

  public class SolutionTest
  {
    public static bool testEqual(long[] v1, long[] v2)
    {
      if (v1.Length != v2.Length) return false;
      for (long i = 0; i < v1.Length; ++i) {
        if (v1[i] != v2[i]) return false;
      }
      return true;
    }

    public static void Main(string[] args)
    {
      Console.Write(testEqual(
        new long[] {1, 3, 2, 5, 3},Digitizer.Digitize(35231))
      );
    }
  }
  
}