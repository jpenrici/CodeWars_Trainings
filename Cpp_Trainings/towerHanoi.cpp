/*
CODEWARS
https://www.codewars.com/kata/5899f1df27926b7d000000eb

"Tower of Hanoi"
*/

#include <iostream>
#include <cmath>

long long towerOfHanoi(int rings)
{
    // Movimentos do Disco = (2^n) -1, n = número de discos.
    return pow(2, rings) - 1;
}

void testequal(long long ans, long long sol)
{
    std::cout << "ans) " << ans  << "\nsol) " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(towerOfHanoi(4), 15);
    testequal(towerOfHanoi(5), 31);
    testequal(towerOfHanoi(10), 1023);

    return 0;  
};
