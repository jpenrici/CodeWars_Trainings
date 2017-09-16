/*
CODEWARS
https://www.codewars.com/kata/557f6437bf8dcdd135000010

"Large Factorials"
*/

#include<iostream>
#include<cstring>

using namespace std;

#define max 5000

void largeFactorial(int vfactor[], int n){
    if (!n) return;
    int c(0);
    for (int i = max - 1; i >= 0; --i){
        vfactor[i] = (vfactor[i] * n) + c;
        c = vfactor[i] * 0.1;
        vfactor[i] %= 10;
    }
    largeFactorial(vfactor, n - 1);
}

string factorial(int factorial){
    if (factorial < 0) return "";
    if (factorial == 0) return "1";
    int *vfactor = new int[max];
    std::memset(vfactor, 0, max * sizeof(int));
    vfactor[max - 1] = 1;
    largeFactorial(vfactor, factorial);
    string out;
    bool c(false);
    for (int i = 0; i < max; i++){
        if (!c && vfactor[i]) c = true;
        if (c) out += to_string(vfactor[i]);
    }    
    return out;
}

void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(factorial(-1), "");
    testequal(factorial(1), "1");
    testequal(factorial(3), "6");
    testequal(factorial(5), "120");
    testequal(factorial(9), "362880");
    testequal(factorial(15), "1307674368000");
    testequal(factorial(20), "2432902008176640000");
    testequal(factorial(25), "15511210043330985984000000");
    std::string f100 = "93326215443944152681699238856266700490715968";
    f100 += "26438162146859296389521759999322991560894146397615651828625369792";
    f100 += "0827223758251185210916864000000000000000000000000";
    testequal(factorial(100), f100);

    return 0;
};
