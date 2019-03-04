/*
CodeWars
https://www.codewars.com/kata/5254ca2719453dcc0b00027d

"Permutations"
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void update(vector<int>& sequence, int pos)
{
    sequence[pos] = sequence[pos] + 1;
    if (sequence[pos] > sequence.size() - 1) {
        sequence[pos] = 0;
        if (pos > 0) update(sequence, pos - 1);
    } else {
        if (sequence[pos] < 0) {
            sequence[pos] = sequence.size() - 1;
            if (pos > 0) update(sequence, pos - 1);
        }
    }
}

bool check(vector<int> sequence)
{
    for (int i = 0; i < sequence.size(); ++i) {
        for (int j = 0; j < sequence.size(); ++j) {
            if (i == j) continue;
            if (sequence[i] == sequence[j]) return true;
        }
    }
    return false;
}

vector<string> permutations(string s)
{
    if (s.empty()) return {""};
    if (s.size() == 1) return {s};
    if (s.size() == 2 && s[0] == s[1]) return {s};

    vector<int> sequence(s.size());   
    for (int i = 0; i < s.size(); ++i) sequence[i] = i;

    set<string> output;
    int limit = pow(s.size(), s.size());
    for (int i = 0; i < limit; ++i) {
        update(sequence, s.size()-1);
        if (!check(sequence)){
            string str("");
            for(int j = 0; j < sequence.size(); ++j)
                str.push_back(s[sequence[j]]);
            output.insert(str);
        }
    }
    return vector<string>(output.begin(), output.end());
}

// Testes
void view(vector<string> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << char(32) << v[i];
    cout << '\n';
}

bool testequal(vector<string> v1, vector<string> v2)
{
    cout << "Expected: ";
    view(v1);
    cout << "Actual  : ";
    view(v2);

    cout << "Result  : ";
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); ++i) {
        auto result = find(begin(v2), end(v2), v1[i]);
        if (result == end(v2)) return false;
    }
    return true;
}

int main()
{
    cout << boolalpha;
    cout << testequal(vector<string> {""}, permutations("")) << '\n';
    cout << testequal(vector<string> {"a"}, permutations("a")) << '\n';
    cout << testequal(vector<string> {"aa"}, permutations("aa")) << '\n';
    cout << testequal(vector<string> {"ab", "ba"}, permutations("ab")) << '\n';
    cout << testequal(vector<string> {"abc", "acb", "bac", "bca",
     "cab", "cba"}, permutations("abc")) << '\n';    
    cout << testequal(vector<string> {"aabb", "abab", "abba", "baab",
     "baba", "bbaa"}, permutations("aabb")) << '\n';
    cout << testequal(
     vector<string> {"abcd", "abdc", "acbd", "acdb", "adbc", "adcb", "bacd",
     "badc", "bcad", "bcda", "bdac", "bdca", "cabd", "cadb", "cbad", "cbda",
     "cdab", "cdba", "dabc", "dacb", "dbac", "dbca", "dcab", "dcba"},
     permutations("abcd")) << '\n';
    cout << testequal(vector<string> {"gkll", "glkl", "gllk", "kgll", "klgl",
     "kllg", "lgkl", "lglk", "lkgl", "lklg", "llgk", "llkg"},
     permutations("gkll")) << '\n';    
    cout << testequal(vector<string> {"aaaab", "aaaba", "aabaa", "abaaa",
     "baaaa"}, permutations("aaaab")) << '\n';

    cout << testequal(vector<string> {"qtz", "qzt", "tqz", "tzq", "zqt", "ztq"},
     permutations("qtz")) << '\n';
    cout << testequal(vector<string> {"zkyz", "zkzy", "zykz", "zyzk", "zzky",
     "zzyk", "kzyz", "kzzy", "kyzz", "yzkz", "yzzk", "ykzz"},
     permutations("zkyz")) << '\n';

    return 0;
}
