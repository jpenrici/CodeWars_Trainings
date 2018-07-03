/*
CODEWARS
https://www.codewars.com/kata/550498447451fbbd7600041c

"Are they the "same"?"
*/
using System;

class AreTheySame
{
    public static bool comp(int[] a, int[] b)
    {
        if (a == null || b == null)
            return false;
        if (a.Length == 0 && b.Length == 0)
            return true;
        if (a.Length == 0 || b.Length == 0)
            return false;

        for (int i = 0; i < a.Length; ++i)
        {
            a[i] *=  a[i];
        }

        Array.Sort<int>(a);
        Array.Sort<int>(b);

        for (int i = 0 ; i < a.Length; i++) 
        {
            if (a[i] != b[i])
                return false;
        }

        return true;
    }
}

class Test
{
    static void Main(string[] args)
    {
        int[] a = new int[] {121, 144, 19, 161, 19, 144, 19, 11};
        int[] b = new int[] {11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19};
        bool r = AreTheySame.comp(a, b); // True
        Console.WriteLine("AreTheySame.comp(a, b): {0}", r);

        int[] a1 = new int[] {0, -14, 191, 161, 19, 144, 195, -1};
        int[] b1 = new int[] {1, 0, 196, 36481, 25921, 361, 20736, 38025};
        bool r1 = AreTheySame.comp(a1, b1); // True
        Console.WriteLine("AreTheySame.comp(a1, b1): {0}", r1); 

        int[] a2 = new int[] {};
        int[] b2 = new int[] {};
        bool r2 = AreTheySame.comp(a2, b2); // True
        Console.WriteLine("AreTheySame.comp(a1, b1): {0}", r2);         
            
        Console.ReadKey();
    }
}
