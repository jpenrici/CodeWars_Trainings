/*
CODEWARS
https://www.codewars.com/kata/544675c6f971f7399a000e79

"Convert a String to a Number!"
*/

#include <iostream>
#include <string>

using namespace std;

int string_to_number(const string &s)
{
    return stoi(s);
}

void testequal(int ans, int sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(string_to_number("123456"), 123456);
    testequal(string_to_number("352605"), 352605);
    testequal(string_to_number("-321405"), -321405);
    testequal(string_to_number("-7"), -7);
    testequal(string_to_number("0"), 0);
    testequal(string_to_number("-0"), 0);

    return 0;
};
