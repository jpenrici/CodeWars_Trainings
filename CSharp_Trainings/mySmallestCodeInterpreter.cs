/*
CodeWars
https://www.codewars.com/kata/526156943dfe7ce06200063e

"My smallest code interpreter (aka Brainf**k)"
*/

using System;
using System.Collections.Generic;
using System.Linq;

public static class Kata
{
    public static string BrainLuck(string code, string input)
    {
        Console.WriteLine("\ncode: {0}, \ninput: {1}", code, input);

        string output = "";
        int indexInput = 0;
        int memoryPtr  = 0;
        int leftBracket  = 0;
        int rigthBracket = 0;
        List<int> memory = new List<int> {0};

        for (int indexCode = 0; indexCode < code.Length; indexCode++)
        {
            switch (code[indexCode])
            {
                case '>':
                    memoryPtr++;
                    if (memoryPtr == memory.Count) 
                    {
                        memory.Add(0);
                        memoryPtr = memory.Count - 1;
                    }
                    break;

                case '<':
                    memoryPtr--;
                    break;

                case '+':
                    if (memory[memoryPtr] == 255) 
                    {
                        memory[memoryPtr] = 0;
                    }
                    else
                    {
                        memory[memoryPtr] += 1;
                    }
                    break;  

                case '-':
                    if (memory[memoryPtr] == 0)
                    {
                        memory[memoryPtr] = 255;
                    }
                    else
                    {
                        memory[memoryPtr] -= 1;     
                    }
                    break;  

                case '.':
                    output += char.ConvertFromUtf32(memory[memoryPtr]);
                    break;

                case ',':
                    if (input.Length != 0)
                    {
                        memory[memoryPtr] = (int)input[indexInput];
                        indexInput++;
                    }
                    break;

                case '[':
                    if (memory[memoryPtr] == 0)
                    {
                        for (int i = indexCode + 1; i < code.Length; i++)
                        {
                            if (code[i] == '[')
                            {
                                leftBracket++;
                            }
                            if (code[i] == ']')
                            {
                                if (leftBracket == 0)
                                {
                                    indexCode = i;
                                    break;
                                }
                                leftBracket--;
                            }
                        }
                    }
                    break;

                case ']':
                    if (memory[memoryPtr] != 0)
                    {
                        for (int i = indexCode - 1; i > 0; i--)
                        {
                            if (code[i] == ']')
                            {
                                rigthBracket++;
                            }
                            if (code[i] == '[')
                            {
                                if (rigthBracket == 0)
                                {
                                    indexCode = i;
                                    break;
                                }
                                rigthBracket--;
                            }
                        }
                    }
                    break;

                default:
                    break;  
            }
        }

        Console.WriteLine("output: {0}", output);
        return output;
    }
}

public class BrainLuckTest
{
    // Echo until byte(255) encountred
    private static void test1()
    {
        testEqual(Kata.BrainLuck(",+[-.,+]",
            "Codewars" + char.ConvertFromUtf32(255)), "Codewars");
    }

    // Echo until byte(0) encountred
    private static void test2()
    {
        testEqual(Kata.BrainLuck(",[.[-],]",
            "Codewars" + char.ConvertFromUtf32(0)), "Codewars");
    }

    // Two numbers multiplier
    private static void test3()
    {
        testEqual(Kata.BrainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.",
            char.ConvertFromUtf32(8) + char.ConvertFromUtf32(9)),
        char.ConvertFromUtf32(72));
    }

    private static void testEqual(string output, string sol)
    {
        Console.WriteLine("Test: {0}", output.Equals(sol));
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("\nTest 1");
        test1();

        Console.WriteLine("\nTest 2");
        test2();

        Console.WriteLine("\nTest 3");
        test3();

        // Console.ReadKey();
    }
}
