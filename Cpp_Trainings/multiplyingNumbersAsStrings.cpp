/*
CODEWARS
https://www.codewars.com/kata/55911ef14065454c75000062

"Multiplying numbers as strings"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string a, string b) {

    if (a.empty() || b.empty()) return "0";

    vector<int> result(a.size() + b.size(), 0);
    int nA(0), nB(0), iA(0), iB(0);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        int c(0);
        nA = a[i] - '0';
        iB = 0;
        for (int j = b.size() - 1; j >= 0; j--)
        {
            nB = b[j] - '0';
            int sum = nA * nB + result[iA + iB] + c;
            c = sum / 10;
            result[iA + iB] = sum % 10;
            iB++;
        }
        if (c > 0) result[iA + iB] += c;
        iA++;
    }
    int i = result.size() - 1;
    while(i >= 0 && result[i] == 0) 
        i--;
    
    if (i == -1) return "0";
    
    string out = "";
    while (i >= 0)
        out += to_string(result[i--]);

    return out;
}


void testequal(string ans, string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(multiply("2", "3"), "6");
    testequal(multiply("30", "69"), "2070");
    testequal(multiply("11", "85"), "935");

    testequal(multiply("2", "0"), "0");
    testequal(multiply("0", "30"), "0");
    testequal(multiply("0000001", "3"), "3");
    testequal(multiply("1009", "03"), "3027");

    testequal(multiply("98765", "56894"), "5619135910");
    testequal(multiply("1020303004875647366210", "2774537626200857473632627613"), "2830869077153280552556547081187254342445169156730");
    testequal(multiply("58608473622772837728372827", "7586374672263726736374"), "444625839871840560024489175424316205566214109298");
    testequal(multiply("9007199254740991", "9007199254740991"), "81129638414606663681390495662081");

    return 0;
};
