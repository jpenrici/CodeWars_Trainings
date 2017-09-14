/*
CODEWARS
https://www.codewars.com/kata/550554fd08b86f84fe000a58

"Which are in?"
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>

class WhichAreIn
{
public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1,
        std::vector<std::string> &array2);
};

// Solução
std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1,
        std::vector<std::string> &array2)
{
    std::vector<std::string> out {};
    for (int i = 0; i < array1.size(); ++i)
    {
        for (int j = 0; j < array2.size(); ++j)
        {
            if (std::regex_match(array2[j].begin(), array2[j].end(),
                std::regex("(.*)?(" + array1[i] + ")(.*)?"))){
                out.push_back(array1[i]);
                break;
            }
        }
    }
    std::sort(std::begin(out), std::end(out));
    return out;
}

// Testes
std::string printVector (std::vector<std::string> v)
{
    if (v.empty()) return "{}";
    std::string s = "{ ";
    for (int i = 0; i < v.size() - 1; ++i)
        s += v[i] + ", ";
    s += v[v.size() - 1] + " }";
    return s;
}

void testequal(std::vector<std::string> ans, std::vector<std::string> sol) {
    std::cout << "ans: " << printVector(ans) << std::endl;
    std::cout << "sol: " << printVector(sol) << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    std::vector<std::string> arr1 = { "arp", "live", "strong" };
    std::vector<std::string> arr2 = { "lively", "alive", "harp",
     "sharp", "armstrong" };
    std::vector<std::string> sol1 = { "arp", "live", "strong" };
    std::vector<std::string> ans1 = WhichAreIn::inArray(arr1, arr2);
    testequal(ans1, sol1);
    
    return 0;
};
