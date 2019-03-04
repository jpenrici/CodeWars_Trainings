/*
CODEWARS
http://www.codewars.com/kata/51b62bf6a9c58071c600001b

"Roman Numerals Encoder"
*/

#include <iostream>
#include <vector>

// Converte número arábico em romano
// (0 < number <= 3999)
std::string solution(int number){

	std::string roman;
	int index(0), mult(1), digit(0);
	std::vector<std::vector<std::string>> v {
		{"",	  "",		  "",		  ""},
		{"I",	  "X",	  "C",	  "M"},
		{"II",	"XX",	  "CC",	  "MM"},
		{"III",	"XXX",	"CCC",	"MMM"},
		{"IV",	"XL",	  "CD",	  "*"},
		{"V",	  "L",	  "D",	  "*"},
		{"VI",	"LX",	  "DC",	  "*"},
		{"VII",	"LXX",	"DCC",	"*"},
		{"VIII","LXXX",	"DCCC",	"*"},
		{"IX",	"XC",	  "CM",	  "*"},
	};

	while (number > 0){
		digit = number % (10 * mult);
		number -= digit;
		roman = v[digit/mult][index++] + roman;
		mult *= 10;
	}

	return roman;
}

// Testes
void testequal(std::string ans, std::string sol) {
  std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
	testequal(solution(182) , "CLXXXII");
	testequal(solution(1990) , "MCMXC");
	testequal(solution(1875) , "MDCCCLXXV");

	int input(1);
	while(input > 0){
		std::cout << "Enter a number (0 < number <= 3999):" << std::endl;
		std::cin >> input;
		if (input > 0 && input <= 3999)
			std::cout << solution(input) << std::endl;
		else
			std::cout << "1 <= number <= 3999 !" << std::endl;
	}
	return 0;
}
