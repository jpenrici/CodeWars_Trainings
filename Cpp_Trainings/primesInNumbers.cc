/*
CODEWARS
https://www.codewars.com/kata/54d512e62a5e54c96200019e

"Primes in numbers"
*/

#include <iostream>
#include <string>

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};

// Solução
std::string PrimeDecomp::factors(int lst)
{
    if (lst == 0 || lst == 1) return '(' + std::to_string(lst) + ')';

    int i(2), count(0);
    std::string expression;
    while(lst >= i) {       
        while (lst % i == 0) {
            lst = lst / i;
            count++;
        }
        if (count > 0) {
            expression += "(" + std::to_string(i);
            if (count > 1) expression += "**" + std::to_string(count);
            expression += ')';
        }
        count = 0;
        i++;
    }

    return expression;
}

// Teste
void testequal(std::string ans, std::string sol) {
    std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(PrimeDecomp::factors(7775460), "(2**2)(3**3)(5)(7)(11**2)(17)");
    testequal(PrimeDecomp::factors(7919), "(7919)");
    testequal(PrimeDecomp::factors(86240), "(2**5)(5)(7**2)(11)");
    
    testequal(PrimeDecomp::factors(36), "(2**2)(3**2)");

    return 0;
};
