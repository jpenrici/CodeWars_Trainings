/*
CODEWARS
https://www.codewars.com/kata/56541980fa08ab47a0000040

"Printer Errors"
*/

#include <iostream>
#include <algorithm>

class Printer
{
public:
	  static bool IsError (char c);
    static std::string printerError(const std::string &s);
};

// Solução
bool Printer::IsError(char c){return !(c >= 'a' && c <= 'm');}
std::string  Printer::printerError(const std::string &s)
{
	int count = count_if(s.begin(), s.end(), Printer::IsError);
	return std::to_string(count) + '/' + std::to_string(s.size());
}

// Testes
void testequal(std::string ans, std::string sol) {
    std::cout << "ans :" << ans << "\nsol :" << sol << std::endl;
    std::cout << "ans = sol: " << std::boolalpha << (ans == sol) << std::endl;
}

void dotest(std::string s, std::string expected)
{
	  std::cout << s << std::endl;
    testequal(Printer::printerError(s), expected);
}

int main()
{
    std::string s = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz";
    dotest(s, "3/56");
    s = "kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz";
    dotest(s, "6/60");
    s = "kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyzuuuuu";
    dotest(s, "11/65");

    return 0;
};
