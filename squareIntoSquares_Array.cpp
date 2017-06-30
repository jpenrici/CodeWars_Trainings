/*
CODEWARS
http://www.codewars.com/kata/54eb33e5bc1a25440d000891

"Square into Squares. Protect trees!"
*/

#include <iostream>
#include <vector>

#define sizeMin 10

class Decomp
{
  public:
  	static std::vector<long long> decompose(long long n);
};

// Solução
std::vector<long long> Decomp::decompose(long long n)
{
	int posArray(1);
	bool running(true);
	long long lastNum(0), num(0);
	long long array[sizeMin];
	std::vector<long long> sol{};

	if (n == 0)
		return {};

	array[posArray] = n;
	while(running){
		lastNum = array[posArray];
		posArray--;
		if (posArray < 0)
			return {};
		num = num + (lastNum * lastNum);
		for(long long i = lastNum - 1; i > 0; --i)
		{
			if(num - (i * i) >= 0){
				num = num - (i * i);
				array[++posArray] = i;
			}
		}
		if(num == 0)
			running = false;
	}
    
    for(int i = posArray; i > 0; --i){
    	sol.push_back(array[i]);
    }

	return sol;
}	

// Imprimir vetor
void printVector(std::vector<long long> v)
{
	if (v.empty())
		std::cout << "Empty!" << std::endl;
	else {
		std::cout << "{ ";
		for (unsigned i = 0; i < v.size() - 1; ++i)
			std::cout << v[i] << " , ";
		std::cout << v[v.size() - 1] << " }" << "\t";
	}
}

// Testes
void testequal(std::vector<long long> ans, std::vector<long long> sol)
{
 	std::cout << "Ans) ";
 	printVector(ans);
 	std::cout << "\nSol) ";
 	printVector(sol);
 	std::cout << "\nAns = Sol: " ;
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(Decomp::decompose(50), {1,3,5,8,49});
    testequal(Decomp::decompose(44), {2,3,5,7,43});
    testequal(Decomp::decompose(11), {1,2,4,10});
    testequal(Decomp::decompose(10), {6, 8});
    testequal(Decomp::decompose(7100), {2,3,5,119,7099});
    testequal(Decomp::decompose(10828), {1,3,6,147,10827});
    testequal(Decomp::decompose(123456), {1,2,7,29,496,123455});
    testequal(Decomp::decompose(4), {});

    return 0;
}
