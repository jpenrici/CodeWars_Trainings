/*
CodeWars
https://www.codewars.com/kata/5547cc7dcad755e480000004

"Is my friend cheating?"
*/

#include <iostream>
#include <vector>

using namespace std;

class RemovedNumbers
{
public:
    static vector<vector<long long> > removNb(long long n);
};

vector<vector<long long> > RemovedNumbers::removNb(long long n)
{
    cout << "N: " << n << "\n";
    vector<vector<long long>> array{};
    long long a{(((1 + n) * n) >> 1) - 2};
    for (long long b = 3; b <= n + 1; ++b, --a) {
        if (a % b == 0 && b * n >= a) array.push_back({b - 1, a / b});
    }
    return array;   
}

string strVector(vector<vector<long long> > v)
{
    string str("{");
    for(int i = 0; i < v.size(); ++i) {
        str += "{ ";
        for (int j = 0; j < v[i].size(); ++j)
            str += to_string(v[i][j]) + char(32);
        str += '}';
    }
    str += '}';
    return str;
}

void testequal(size_t line, vector<vector<long long>> ans,
    vector<vector<long long>> sol)
{
    cout << "Line [" << line << "]:\n";
    cout << "ans: " << strVector(ans) << "\nsol: " << strVector(sol) << '\n'
              << boolalpha << (ans == sol) << '\n';
}

void test()
{
    vector<vector<long long>> r1 = {{15, 21}, {21, 15}};
    testequal(__LINE__,RemovedNumbers::removNb(26), r1);

    vector<vector<long long>> r2 = {};
    testequal(__LINE__,RemovedNumbers::removNb(100), r2);

    vector<vector<long long>> r3 = {{550320, 908566}, {559756, 893250},
        {893250, 559756}, {908566, 550320}};
    testequal(__LINE__,RemovedNumbers::removNb(1000003), r3);

    vector<vector<long long>> r4 = {{133042, 264628}, {264628, 133042}};
    testequal(__LINE__,RemovedNumbers::removNb(265356), r4);
}

int main()
{
    test();
    return 0;
}

/*
DETAILS:

A friend of mine takes a sequence of numbers from 1 to n (where n > 0).
Within that sequence, he chooses two numbers, a and b.
He says that the product of a and b should be equal to the sum of all numbers
in the sequence, excluding a and b.
Given a number n, could you tell me the numbers he excluded from the sequence?
The function takes the parameter: n (n is always strictly greater than 0) and
returns an array or a string (depending on the language) of the form:

[(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or or [{a, b}, ...]
with all (a, b) which are the possible removed numbers in the sequence 1 to n.

[(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or ...will be sorted in
increasing order of the "a".

It happens that there are several possible (a, b). The function returns an
empty array (or an empty string) if no possible numbers are found which will
prove that my friend has not told the truth! (Go: in this case return nil).

(See examples of returns for each language in "RUN SAMPLE TESTS")

Examples:

removNb(26) should return [(15, 21), (21, 15)]
or

removNb(26) should return { {15, 21}, {21, 15} }
or

removeNb(26) should return [[15, 21], [21, 15]]
or

removNb(26) should return [ {15, 21}, {21, 15} ]
or

removNb(26) should return "15 21, 21 15"
or

in C:
removNb(26) should return  **an array of pairs {{15, 21}{21, 15}}**
tested by way of strings.
*/
