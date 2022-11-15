/*
CODEWARS
https://www.codewars.com/kata/54a91a4883a7de5d7800009c

"String incrementer"
*/

#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>

using namespace std;

string incrementString(const string &str)
{
    if (str.empty()) {
        return "1";
    }

    string new_str = str;

    int number = 0;
    int digits = 0;
    while (isdigit(new_str.back())) {
        number += (new_str.back() - '0') * pow(10, digits);
        new_str.pop_back();
        digits++;
    }

    number++;
    if (to_string(number).size() < digits) {
        string zeros(digits - to_string(number).size(), '0');
        new_str.append(zeros);
    }
    new_str.append(to_string(number));

    return new_str;
}

void testequal(string ans, string sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(incrementString("foobar000"), "foobar001");
    testequal(incrementString("foo"), "foo1");
    testequal(incrementString("foobar001"), "foobar002");
    testequal(incrementString("foobar99"), "foobar100");
    testequal(incrementString("foobar099"), "foobar100");
    testequal(incrementString(""), "1");
    testequal(incrementString("foobar9"), "foobar10");
    testequal(incrementString("foobar23"), "foobar24");
    testequal(incrementString("foobar42"), "foobar43");

    return 0;
};
