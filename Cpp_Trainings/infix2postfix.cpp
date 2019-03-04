/*
CODEWARS - Estudo de Solução
https://www.codewars.com/kata/52e864d1ffb6ac25db00017f

"Infix to Postfix Converter"

Construct a function that, when given a string containing an expression in infix
notation, will return an identical expression in postfix notation.

The operators used will be +, -, *, /, and ^ with standard precedence rules and
left-associativity of all operators but ^.

The operands will be single-digit integers between 0 and 9, inclusive.

Parentheses may be included in the input, and are guaranteed to be in correct
pairs.

You may read more about postfix notation, also called Reverse Polish notation,
here: http://en.wikipedia.org/wiki/Reverse_Polish_notation
*/

#include <iostream>
#include <sstream>
#include <stack>

int getPriority(char character)
{
    switch (character) {
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

std::string to_postfix(const std::string& infix) 
{
    std::stack<char> stack_tmp;
    std::stringstream postfix;

    for (char character : infix) {
        if (std::isdigit(character)) {
            postfix << character;
        } else if (character == '(') {
            stack_tmp.push(character);
        } else if (character == ')') {
            while (stack_tmp.top() != '(') {
                postfix << stack_tmp.top();
                stack_tmp.pop();
            }
            stack_tmp.pop();
        } else {
            while (!stack_tmp.empty() && getPriority(character) <= getPriority(stack_tmp.top())) {
                postfix << stack_tmp.top();
                stack_tmp.pop();
            }
            stack_tmp.push(character);
        }
    }

    while (!stack_tmp.empty()) {
        postfix << stack_tmp.top();
        stack_tmp.pop();
    }

    // std::cout << infix << ":" << postfix.str() << ":" << std::endl;
    return postfix.str();
}

void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

main()
{
    testequal(to_postfix(""), "");
    testequal(to_postfix("2+7*5"), "275*+");
    testequal(to_postfix("2*5+7"), "25*7+");
    testequal(to_postfix("3*3/(7+1)"), "33*71+/");
    testequal(to_postfix("5+(6-2)*9+3^(7-1)"), "562-9*+371-^+");
    testequal(to_postfix("(5-4-1)+9/5/2-7/1/7"), "54-1-95/2/+71/7/-");
    testequal(to_postfix("7*6+8"), "76*8+");
    testequal(to_postfix("1*7+4"), "17*4+");

    return 0;
};
