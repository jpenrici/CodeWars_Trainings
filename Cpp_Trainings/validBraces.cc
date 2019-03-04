/*
CODEWARS
https://www.codewars.com/kata/5277c8a221e209d3f6000b56

"Valid Braces"
*/

#include <iostream>

bool valid_braces(std::string braces) 
{
    if (braces.empty()) return false;
    if (braces.size() % 2 != 0) return false;

    std::string stack;
    char brace;
    for (int index = 0; index < braces.size(); ++index)
    {
        brace = braces[index];
        if (brace == '(' || brace == '[' || brace == '{'){
            // std::cout << "Push " << brace << std::endl;
            stack.push_back(brace);
            continue;
        } 
        if (stack.empty()) return false;
        if ((brace == ')' && stack.back() == '(') ||
            (brace == ']' && stack.back() == '[') ||
            (brace == '}' && stack.back() == '{')){
            // std::cout << "Pop " << brace << std::endl;
            stack.pop_back();
        } else { return false; }
    }
    return stack.empty();
}

void testequal(std::string  ans, bool exp)
{
    bool sol = valid_braces(ans);
    std::cout << "ans: " << ans;
    std::cout << "\texp: " << std::boolalpha << exp;
    std::cout << "\tsol: " << std::boolalpha << sol;
    if (sol == exp) std::cout << "\tOK" << std::endl;
    else std::cout << "\tError" << std::endl;
}

int main()
{
    testequal("()" , true);
    testequal( "[(])",  false);
    testequal("(){}[]", true);
    testequal("(}", false);
    testequal("([{}])", true);
    testequal("", false);
    testequal(")", false);
    testequal("]", false);
    testequal("}", false);
    testequal("{(}", false);
    testequal("{[()]}", true);
    testequal("(])[", false);
    testequal("{{{{{{(((((([][][]))))))}}}}}}", true);

    return 0;  
};
