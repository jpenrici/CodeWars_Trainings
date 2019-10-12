/*
CodeWars
https://www.codewars.com/kata/two-to-one/cpp

"Two to One"
*/

#include <iostream>
#include <algorithm>
#include <string>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2) {
        std::string str = s1 + s2;
        sort(str.begin(), str.end());
        auto res = unique(str.begin(), str.end()); 
        return std::string(str.begin(), res);
    }
};

void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << '\n'
        << std::boolalpha << (ans == sol) << '\n';
}

void dotest(std::string a1, std::string a2, std::string expected)
{
    testequal(TwoToOne::longest(a1, a2), expected);
}

int main()
{
    dotest("xyaabbbccccdefww", "xxxxyyyyabklmopq", "abcdefklmopqwxy");
    dotest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
    dotest("aretheyhere", "yestheyarehere", "aehrsty");
    dotest("loopingisfunbutdangerous", "lessdangerousthancoding", "abcdefghilnoprstu");

    return 0;
}