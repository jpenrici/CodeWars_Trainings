/*
CODEWARS
https://www.codewars.com/kata/5616868c81a0f281e500005c

"Prize Draw"

To participate in a prize draw each one gives his/her firstname.

Each letter of a firstname has a value which is its rank in the English
alphabet. A and a have rank 1, B and b rank 2 and so on.

The length of the firstname is added to the sum of these ranks hence
a number n. An array of random weights is linked to the firstnames and
each n is multiplied by its corresponding weight to get what they 
a winning number.

Example: names: COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH weights:
[1, 4, 4, 5, 2, 1]

PAUL -> n = length of firstname + 16 + 1 + 21 + 12 = 4 + 50 -> 54
The weight associated with PAUL is 2
so Paul's winning number is 54 * 2 = 108.

Now one can sort the firstnames in decreasing order of the winning
numbers. When two people have the same winning number sort them
alphabetically by their firstnames.

#Task:

parameters: st a string of firstnames, we an array of weights,
n a rank

return: the firstname of the participant whose rank is
n (ranks are numbered from 1)

#Example: names: COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH
weights: [1, 4, 4, 5, 2, 1] n: 4

The function should return: PauL

#Note: If st is empty return "No participants".

If n is greater than the number of participants then
return "Not enough participants".
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Rank
{
public:
    static std::string nthRank(const std::string &st, std::vector<int> &we, int n);
    static std::vector<std::string> split(const std::string &s, char delim);
};

// Solução
std::string Rank::nthRank(const std::string &st, std::vector<int> &we, int n)
{
	struct ranks {
		int rank;
		std::string firstname;
	};
	ranks temp;
	int ascii, sum;
	std::vector<ranks> listRank;
	std::vector<std::string> firstnames;
	
	if(st.empty())
		return "No participants";
	
	// Calcular o rank de todos os nomes	
	firstnames = split(st, char(44));	// Split [,]
	if(unsigned(n) > firstnames.size())
		return "Not enough participants";
	
	for (unsigned i = 0; i < firstnames.size() ; i++)
	{
		sum = 0;
		for (unsigned j = 0; j < firstnames[i].length(); j++)
		{	
			ascii = int(firstnames[i][j]);
			if (ascii >= 65 && ascii <= 90)		// [A - Z]
				sum = sum + 1 + ascii - 65;
			if (ascii >= 97 && ascii <= 122)	// [a - z]
				sum = sum + 1 + ascii - 97;
		}
		sum = sum + firstnames[i].length();
		temp.rank = sum * we[i];
		temp.firstname = firstnames[i];
		listRank.push_back(temp);
	}
/*
	// Imprime vetor de struct
	for (unsigned i = 0; i < listRank.size(); i++)
	{
		std::cout << "[" << i << "] ";
		std::cout << listRank[i].rank << " ";
		std::cout << listRank[i].firstname << "\t";
	}
	std::cout << std::endl;
*/
	// Ordenar por rank
	for(unsigned i = listRank.size() - 1; i >= 1; i--)
		for (unsigned j = 0; j < i; j++){
			if (listRank[j].rank < listRank[j + 1].rank){
				temp = listRank[j];
				listRank[j] = listRank[j + 1];
				listRank[j + 1] = temp;
			}
			if ((listRank[j].rank == listRank[j + 1].rank) &&
			(listRank[j].firstname > listRank[j + 1].firstname)){
				temp = listRank[j];
				listRank[j] = listRank[j + 1];
				listRank[j + 1] = temp;
			}
		}
/*			
	// Imprime vetor de struct
	for (unsigned i = 0; i < listRank.size(); i++)
	{
		std::cout << "[" << i << "] ";
		std::cout << listRank[i].rank << " ";
		std::cout << listRank[i].firstname << "\t";
	}
	std::cout << std::endl;
*/
	return listRank[n - 1].firstname;
}

// Split C++
std::vector<std::string> Rank::split(const std::string &s, char delim)
{
  std::vector<std::string> group;
  std::stringstream copy(s);
  std::string substring;
  while(getline(copy, substring, delim))
    group.push_back(substring);
  return group;  // Retorna Split
}

// Testes
void testequal(std::string ans, std::string sol) {
    std::cout << "Ans) " << ans << "\nSol) " << sol << "\nAns = Sol: " ;
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}
void dotest(const std::string &st, std::vector<int> &we, int n, std::string expected)
{
    testequal(Rank::nthRank(st, we, n), expected);
}

int main()
{
	std::string st, sol;
	std::vector<int> we;
	
	st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
	we = {4, 2, 1, 4, 3, 1, 2};
	sol = "Benjamin";
	dotest(st, we, 4, sol);

	st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
	we = {1, 3, 5, 5, 3, 6};
	sol = "Matthew";
	dotest(st, we, 2, sol);
	
	//Example: names: COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH
	//weights: [1, 4, 4, 5, 2, 1] n: 4
	st = "COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH";
	we = {1, 4, 4, 5, 2, 1};
	sol = "PauL";
	dotest(st, we, 4, sol);

	return 0;
  }
