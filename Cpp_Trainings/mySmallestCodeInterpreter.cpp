/*
CodeWars
https://www.codewars.com/kata/526156943dfe7ce06200063e

"My smallest code interpreter (aka Brainf**k)"
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::string brainLuck(std::string code, std::string input)
{
    std::string ans("");

    std::vector<char> memory(1,0);
    std::vector<char>::iterator memoryPtr = memory.begin();

    std::string::iterator codePtr = code.begin();
    std::stack<std::string::iterator> codeStack;

    std::cout << "code: " << code << "\ninput: " << input << '\n';
    while (codePtr != code.end()) {
        switch (*codePtr) {
            case '>':
                memoryPtr++;
                if (memoryPtr == memory.end()) {
                    memory.push_back(0);
                    memoryPtr = memory.end() - 1;
                }
                break;

            case '<':
                memoryPtr--;
                break;

            case '+':
                if (*memoryPtr == 255) (*memoryPtr) = 0;
                else (*memoryPtr) += 1;
                break;  

            case '-':
                if (*memoryPtr == 0) (*memoryPtr) = 255;
                else (*memoryPtr) -= 1;
                break;  

            case '.':
                ans.append(1, *memoryPtr);
                break;

            case ',':
                if (!input.empty()) {
                    *memoryPtr = input.front();
                    input.erase(input.begin());
                }
                break;  

            case '[':
                codeStack.push(codePtr);
                if (*memoryPtr == 0) {
                    auto startCodePtr = codePtr;
                    while (++codePtr != code.end()) {
                        if (*codePtr == '[') {
                            codeStack.push(codePtr);
                        } else {
                            if (*codePtr == ']') {
                                if (codeStack.empty()) {
                                    throw std::runtime_error("[] error!");
                                }
                                auto tempPtr = codeStack.top();
                                codeStack.pop();
                                if (startCodePtr == tempPtr) break;
                            }
                        }
                    }
                }
                break;

            case ']':
                if (codeStack.empty()) throw std::runtime_error("[] error!");
                if (*memoryPtr != 0) codePtr = codeStack.top();
                else codeStack.pop();
                break;

            default:
                break;  
        }
        codePtr++;
    }

    if (!codeStack.empty()) throw std::runtime_error("[] error!");

    return ans;
}

void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

void test()
{
       //echo until "255"
       std::string tw = "codewars";
       tw.append(1,(char)255);
       testequal(brainLuck(",+[-.,+]",tw), "codewars");

       //echo until "0";
       std::string mw = "codewars";
       mw.append(1,(char)0);
       testequal(brainLuck(",[.[-],]",mw), "codewars");
       
       //two number multiplier
       std::string dw;
       dw.append(1, (char) 7);
       dw.append(1, (char) 3);
       std::string result;
       result.append(1, (char)21);
       testequal(brainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.",dw), result);
}

int main()
{
    test();
    return 0;
}

/*
Details

Inspired from real-world Brainf**k, we want to create an interpreter of that
language which will support the following instructions (the machine memory or
'data' should behave like a potentially infinite array of bytes, initializedto 0):

> increment the data pointer (to point to the next cell to the right).
< decrement the data pointer (to point to the next cell to the left).
+ increment (increase by one, truncate overflow: 255 + 1 = 0) the byte at the data pointer.
- decrement (decrease by one, treat as unsigned byte: 0 - 1 = 255 ) the byte at the data pointer.
. output the byte at the data pointer.
, accept one byte of input, storing its value in the byte at the data pointer.
[ if the byte at the data pointer is zero, then instead of moving the instruction
  pointer forward to the next command, jump it forward to the command after
  the matching ] command.
] if the byte at the data pointer is nonzero, then instead of moving the instruction
  pointer forward to the next command, jump it back to the command after the matching
  [ command.

The function will take in input...

the program code, a string with the sequence of machine instructions,
the program input, a string, eventually empty, that will be interpreted as an
array of bytes using each character's ASCII code and will be consumed by the ,
instruction

... and will return ...

the output of the interpreted code (always as a string), produced by the . instruction.

https://en.wikipedia.org/wiki/Brainfuck
*/