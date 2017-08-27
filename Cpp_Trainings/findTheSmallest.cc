/*
CODEWARS
https://www.codewars.com/kata/573992c724fc289553000e95

"Find the smallest"
*/

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n);
};

// Solução
std::vector<long long> ToSmallest::smallest(long long n)
{
	// long long -> string
	std::stringstream buffer;
	buffer << n;
	std::string digits = buffer.str();
	buffer.str("");

	// vetores
	std::vector<long long> result{n, 0, 0};
	std::vector<long long> vtmp{0, 0, 0};

	// checar alternativas
	std::cout << "\n" << n << std::endl;
	for (int i = 0; i < digits.size(); ++i)
	{
		for (int j = 0; j < digits.size(); ++j)
		{
			std::string tmp = digits;
			tmp.erase(i, 1);
			tmp.insert(j, 1, digits[i]);
			vtmp[0] = std::stoll(tmp);
			vtmp[1] = i;
			vtmp[2] = j;
			if (vtmp < result){
				result = vtmp;
				std::cout << vtmp[0] << " : " << vtmp[1];
				std::cout << " -> " << vtmp[2] << std::endl;
			}
		}
	}
	return result;
}

// Testes
void testequal(std::vector<long long> ans, std::vector<long long> sol)
{
    std::cout << "ans {" << ans[0] << "," << ans[1] << "," << ans[2] << "}";
    std::cout << "\nsol {" << sol[0] << "," << sol[1] << "," << sol[2] << "}";
    std::cout << "\nans = sol: " << std::boolalpha << (ans == sol) << std::endl;
}

static void dotest(long long n, std::vector<long long> expected)
{
    testequal(ToSmallest::smallest(n), expected);
}

int main() 
{
    dotest(261235, {126235, 2, 0});
    dotest(209917, {29917, 0, 1});
    dotest(285365, {238565, 3, 1});
    dotest(269045, {26945, 3, 0});
    dotest(296837, {239687, 4, 1});
    dotest(1000000, {1, 0, 6});

    std::cout << std::endl;
    dotest(1, {1, 0, 0});
    dotest(12345, {12345, 0, 0});
    dotest(11111111, {11111111,0,0});
    dotest(211111111, {111111112,0,8});
    dotest(1234567890000000123,{123456789000000123, 9, 0});

    return 0;
};
