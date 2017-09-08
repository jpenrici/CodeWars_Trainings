/*
CODEWARS
https://www.codewars.com/kata/584466950d3bedb9b300001f

"How many times does it contain?"
*/

#include <iostream>
#include <string>
#include <algorithm>

// Solução
static int stringCounter(std::string inputS,char charS){
    return std::count(inputS.begin(), inputS.end(), charS);
}

// Teste
void testequal(std::string ansS, char ansC , int sol) {
    int ans = stringCounter(ansS, ansC);
    std::cout << ansS << " : " << ansC << std::endl;
    std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal("Hello World",'o', 2);
    testequal("Wait isn't it supposed to be cynical?",'i', 4);
    testequal("I'm gona be the best code warrior ever dad",'r', 4);
    testequal("Do you like Harry Potter?",'?', 1);

    return 0;
};
