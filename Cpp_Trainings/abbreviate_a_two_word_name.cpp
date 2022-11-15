/*
CODEWARS
https://www.codewars.com/kata/57eadb7ecd143f4c9c0000a3

"Abbreviate a Two Word Name"
*/

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

string abbrevName(string name)
{
    istringstream iss(name);
    vector<string> tokens;
    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         back_inserter(tokens));

    string result = "";
    if (tokens.size() >= 2) {
        result.push_back(toupper(tokens[0].front()));
        result.push_back('.');
        result.push_back(toupper(tokens[1].front()));
    }

    return result;
}

void testequal(string ans, string sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(abbrevName("Sam Harris"), "S.H");
    testequal(abbrevName("Patrick Feenan"), "P.F");
    testequal(abbrevName("Evan Cole"), "E.C");
    testequal(abbrevName("P Favuzzi"), "P.F");
    testequal(abbrevName("David Mendieta"), "D.M");

    return 0;
};
