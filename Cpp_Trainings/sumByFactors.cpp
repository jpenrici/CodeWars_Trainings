/*
CODEWARS - Estudo de Solução
https://www.codewars.com/kata/54d496788776e49e6b00052f

"Sum by Factors"
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int> &lst);
};

// Solução
std::string SumOfDivided::sumOfDivided(std::vector<int> &lst)
{
    std::map<int, int> mapNumbers;
    for (auto n: lst) {
        int number = abs(n);
        int prime = 2;
        while (number != 1) {
          if (number % prime == 0) {
            mapNumbers[prime] += n;
            while (number % prime == 0) number /= prime;
          }
          prime++;
        }
    }
    std::string out;
    for (auto it: mapNumbers) {
        out += "(" + std::to_string(it.first) + " " + std::to_string(it.second) + ")";
    }

    return out;
}

// Teste
void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    std::vector<int> d1 = {12, 15};
    std::string ans1 = SumOfDivided::sumOfDivided(d1);
    std::string sol1 = "(2 12)(3 27)(5 15)";
    testequal(ans1, sol1);

    return 0;
};
