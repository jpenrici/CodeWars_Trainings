/*
CODEWARS - Estudo de Solução
https://www.codewars.com/kata/51b6249c4612257ac0000005

"Roman Numerals Decoder"

Create a function that takes a Roman numeral as its argument and returns its
value as a numeric decimal integer. You don't need to validate the form of the
Roman numeral.

Modern Roman numerals are written by expressing each decimal digit of the number
to be encoded separately, starting with the leftmost digit and skipping any 0s.
So 1990 is rendered "MCMXC" (1000 = M, 900 = CM, 90 = XC) and 2008 is rendered
"MMVIII" (2000 = MM, 8 = VIII). The Roman numeral for 1666, "MDCLXVI", uses each
letter in descending order.

Example: "XXI"); // => 21
*/

#include <iostream>
#include <string>
using namespace std;

// Solução
int value(char r)
{
    switch (r) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return -1;
}

int solution(string roman) {

    if (roman.empty()) return 0;
    int sum(0);
    for (int i = 0; i < roman.length(); ++i)
    {
        int num1 =  value(roman[i]);
        if (i + 1 < roman.length()){
            int num2 =  value(roman[i+1]);
            if (num1 >= num2) {
                sum = sum + num1;
            } else {
                sum = sum + num2 - num1;
                i++;
            }
        } else {
            sum = sum + num1;
            i++;
        }
    }
    return sum;
}

// Testes
void testequal(string roman, int sol)
{
    int ans = solution(roman);
    cout << "roman: " << roman << endl;
    cout << "ans: " << ans << "\nsol: " << sol << endl;
    cout << boolalpha << (ans == sol) << endl;
}


int main()
{
    testequal("XXI", 21);
    testequal("I", 1);
    testequal("IV", 4);
    testequal("MMVIII", 2008);
    testequal("MDCLXVI", 1666);

    return 0;
};
