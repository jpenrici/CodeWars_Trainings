/*
CODEWARS
http://www.codewars.com/kata/51b66044bce5799a7f000003

"Roman Numerals Helper"
*/

#include <iostream>
#include <vector>

struct RomanNumerals {
    std::vector<std::string> symbol = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    std::vector<int> numbers = {
        1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,  1
    };  
    std::string to_roman(int number);
    int from_roman(std::string roman);
    int getNumber(std::string str);
} RomanNumerals;

int RomanNumerals::getNumber(std::string str)
{
    for(int i = 0; i < symbol.size(); ++i) {
        if (str == symbol[i]) return numbers[i];
    }
    return 0;   
}

// Roman Numerals Encoder
std::string RomanNumerals::to_roman(int number)
{
    int i(0);
    std::string roman("");
    while (number > 0 && i < numbers.size()) {
        if (number >= numbers[i]) {
            number = number - numbers[i];
            roman = roman + symbol[i];
        } else {
            i = i + 1;
        }
    }
    return roman;
}

// Roman Numerals Decoder
int RomanNumerals::from_roman(std::string roman)
{
    if (roman.empty()) return 0;

    int number(0);
    std::string num;
    for (int i = 0; i < roman.length(); ++i)
    {
        num = "";
        num.push_back(roman[i]);
        int num1 =  getNumber(num);
        if (i + 1 < roman.length()){
            num = "";
            num.push_back(roman[i+1]);
            int num2 =  getNumber(num);
            if (num1 >= num2) {
                number = number + num1;
            } else {
                number = number + num2 - num1;
                i++;
            }
        } else {
            number = number + num1;
            i++;
        }
    }
    return number;
}

void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\tsol: " << sol << "\t"
            << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    // To roman
    testequal(RomanNumerals.to_roman(1000), "M");
    testequal(RomanNumerals.to_roman(182) , "CLXXXII");
    testequal(RomanNumerals.to_roman(1990), "MCMXC");
    testequal(RomanNumerals.to_roman(1875), "MDCCCLXXV");

    // From roman
    testequal( std::to_string(RomanNumerals.from_roman("M")), std::to_string(1000));
    testequal( std::to_string(RomanNumerals.from_roman("XXI")), std::to_string(21));
    testequal( std::to_string(RomanNumerals.from_roman("XXX")), std::to_string(30));
    testequal( std::to_string(RomanNumerals.from_roman("I")), std::to_string(1));
    testequal( std::to_string(RomanNumerals.from_roman("IV")), std::to_string(4));
    testequal( std::to_string(RomanNumerals.from_roman("MMVIII")), std::to_string(2008));
    testequal( std::to_string(RomanNumerals.from_roman("MDCLXVI")), std::to_string(1666));

    return 0;
}

/*
Describe(any_group_name_you_want)
{
    It(should_do_something)
    {
        Assert::That(RomanNumerals.from_roman("MDCLXVI"), Equals(1666));
        Assert::That(RomanNumerals.to_roman(1875), Equals("MDCCCLXXV"));
        // Assert::That(
        // "Instead I ran tests without changing anything and thats why this is failing",
        // Equals("I added my own tests for TDD based development"));
    }
};
*/
