/*
CODEWARS
https://www.codewars.com/kata/55c04b4cc56a697bb0000048

"Scramblies"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool scramble(const string &s1, const string &s2)
{

    if (s1 == s2) {
        return true;
    }

    vector<int> count(256, 0);
    for (unsigned int i = 0; i < s1.size(); i++) {
        count[s1[i]]++;
    }

    for (unsigned int i = 0; i < s2.size(); i++) {
        if (count[s2[i]] == 0) {
            return false;
        }
        count[s2[i]]--;
    }

    return true;
}

void testequal(string str1, string str2, bool sol)
{
    bool ans = scramble(str1, str2);
    cout << "str1:" << str1 << "\nstr2:" << str2 << '\n';
    cout << boolalpha << "ans: " << ans << "\nsol: " << sol << '\n'
         << (ans == sol) << '\n';
}

int main()
{
    testequal("rkqodlw", "world", true);
    testequal("cedewaraaossoqqyt", "codewars", true);
    testequal("katas", "steak", false);
    testequal("scriptjavx", "javascript", false);
    testequal("scriptingjava", "javascript", true);
    testequal("scriptsjava", "javascript", true);
    testequal("javscripts", "javascript", false);
    testequal("aabbcamaomsccdd", "commas", true);
    testequal("commas", "commas", true);
    testequal("sammoc", "commas", true);

    return 0;
};
