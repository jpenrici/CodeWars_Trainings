/*
CODEWARS
https://www.codewars.com/kata/57a0885cbb9944e24c00008e

"Remove exclamation marks"
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string removeExclamationMarks(string str)
{
    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    return str;
}

void testequal(string ans, string sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(removeExclamationMarks("Hello World!"), "Hello World");
    testequal(removeExclamationMarks("Hello World!!!"), "Hello World");
    testequal(removeExclamationMarks("Hi! Hello!"), "Hi Hello");
    testequal(removeExclamationMarks("Hi!!! Hello!"), "Hi Hello");
    testequal(removeExclamationMarks("Hi! He!l!lo!"), "Hi Hello");

    return 0;
};
