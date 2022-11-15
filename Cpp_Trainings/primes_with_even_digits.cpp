/*
CODEWARS
https://www.codewars.com/kata/582dcda401f9ccb4f0000025

"Primes with Even Digits"
*/

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(unsigned int n)
{

    if (n <= 1) {
        return false;
    }

    for (unsigned int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

unsigned int countEven(unsigned int n)
{

    int counter = 0;
    while (n > 0) {
        int rem = n % 10;
        if (rem % 2 == 0) {
            counter++;
        }
        n /= 10;
    }
    return counter;
}

unsigned int f(unsigned int n)
{

    unsigned int max_value = 0;
    unsigned int max_counter = 0;

    for (unsigned int i = n - 1; i > 2; i--) {
        if (i % 2 != 0) {
            unsigned int counter = countEven(i);
            if (counter > max_counter) {
                if (isPrime(i)) {
                    max_value = i;
                    max_counter = counter;
                }
            }
        }
    }

    return max_value;
}

void testequal(unsigned int ans, unsigned int sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{

    testequal(f(1000), 887);
    testequal(f(10000), 8887);
    testequal(f(500), 487);
    testequal(f(487), 467);

    return 0;
};
