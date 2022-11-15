/*
CODEWARS
https://www.codewars.com/kata/5324945e2ece5e1f32000370

"Sum Strings as Numbers"
*/

#include <iostream>
#include <string>

using namespace std;

string sum_strings(const string &a, const string &b)
{

    string A = a;
    string B = b;

    int diff = A.size() - B.size();
    if (diff > 0) {
        string temp(diff, '0');
        B = temp + b;
    }
    if (diff < 0) {
        string temp(-diff, '0');
        A = temp + a;
    }

    int value = 0;
    int extra = 0;
    string sum = "";
    while (!A.empty()) {
        value = (int)(A.back() - '0') + (int)(B.back() - '0') + extra;
        extra = 0;
        if (value >= 10) {
            value -= 10;
            extra = 1;
        }
        sum = to_string(value) + sum;
        A.pop_back();
        B.pop_back();
    }
    if (extra == 1) {
        sum = "1" + sum;
    }

    return sum;
}

void testequal(string ans, string sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(sum_strings("0", "0"), "0");
    testequal(sum_strings("10", "2"), "12");
    testequal(sum_strings("99", "2"), "101");
    testequal(sum_strings("2", "109"), "111");
    testequal(sum_strings("1", "1009"), "1010");
    testequal(sum_strings("123", "456"), "579");

    return 0;
};
