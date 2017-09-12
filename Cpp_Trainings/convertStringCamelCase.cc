/*
CODEWARS
https://www.codewars.com/kata/517abf86da9663f1d2000003

"Convert string to camel case"
*/

#include <iostream>
#include <string>
#include <cctype>

// Solução
std::string to_camel_case(std::string text) {
    std::string out;
    for (int i = 0; i < text.size(); ++i)
    {
        if (!isalpha(text[i]) && isalpha(text[i + 1])){
            if (islower(text[i + 1])) out += toupper(text[i + 1]);
            else out += text[i + 1];
            i++;
            continue;
        }
        out += text[i];
    }
    return out;
}

// Testes
void testequal(std::string s, std::string sol)
{
    std::string ans = to_camel_case(s);
    std::cout << s << std::endl;
    std::cout << "ans) " << ans << "\nsol) " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal("the-stealth-warrior", "theStealthWarrior");
    testequal("The_Stealth_Warrior", "TheStealthWarrior");

    testequal("the_stealth_warrior", "theStealthWarrior");
    testequal("The-Stealth-Warrior", "TheStealthWarrior");
    testequal("A-B-C", "ABC");
    testequal("a b c", "aBC");

    return 0;
};
