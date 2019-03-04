/*
CODEWARS
https://www.codewars.com/kata/5541f58a944b85ce6d00006a

"Product of consecutive Fib numbers"
*/

#include <iostream>
#include <vector>

typedef unsigned long long ull;

class ProdFib
{
public:
    static std::vector<ull> productFib(ull prod);
};

// Solução
std::vector<ull> ProdFib::productFib(ull prod)
{
    int i(2);
    ull prodFib(0);
    std::vector<ull> f {1, 1};
    while (i <= prod + 1) {
        f.push_back(f[i - 1] + f[i - 2]);
        prodFib = f[i - 1] * f[i - 2];
        if (prodFib >= prod) break;
        i++;
    }
    return {f[i - 2], f[i - 1], (prodFib == prod)};
}

// Testes
void testequal(ull  prod, std::vector<ull> ans, std::vector<ull> sol)
{
    std::cout << "Number: " << prod << std::endl;
    std::cout << "ans: {" << ans[0] << "," << ans[1] << "," << ans[2] << "}";
    std::cout << "\nsol: {" << sol[0] << "," << sol[1] << "," << sol[2] << "}";
    std::cout << "\nans = sol: " << std::boolalpha << (ans == sol) << std::endl;
}

void dotest(ull prod, std::vector<ull> expected)
{
    testequal(prod, ProdFib::productFib(prod), expected);
}

int main()
{
    dotest(4895, {55, 89, true});
    dotest(5895, {89, 144, false});
    dotest(74049690, {6765, 10946, 1ULL});
    dotest(84049690, {10946, 17711, 0ULL});

    dotest(2, {1, 2, true});
    dotest(15, {3, 5, true});
    
    return 0;
};
