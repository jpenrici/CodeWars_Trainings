/*
CODEWARS
https://www.codewars.com/kata/56e3cd1d93c3d940e50006a4

"How Green Is My Valley?"

* Input : an array of integers.
* Output : this array,
		   but sorted in such a way that there are two wings:

    * the left wing with numbers decreasing,
    * the right wing with numbers increasing.
    * the two wings have the same length. If the length of the array is
      odd the wings are around the bottom, if the length is even the
      bottom is considered to be part of the right wing.
	* each integer l of the left wing must be greater or equal to its
	  counterpart r in the right wing, the difference l - r being as
	  small as possible. In other words the right wing must be nearly
	  as steeply as the left wing.

The function is make_valley or makeValley or make-valley.

a = [79, 35, 54, 19, 35, 25]
make_valley(a) --> [79, 35, 25, *19*, 35, 54]
The bottom is 19, left wing is [79, 35, 25],
right wing is [*19*, 35, 54].

79..................54
    35..........35
        25. 
          ..19

a = [67, 93, 100, -16, 65, 97, 92]
make_valley(a) --> [100, 93, 67, *-16*, 65, 92, 97]
The bottom is -16, left wing [100, 93, 67] and
right wing [65, 92, 97] have same length.

100.........................97
    93..........
               .........92
        67......
               .....65
            -16     

a = [66, 55, 100, 68, 46, -82, 12, 72, 12, 38]
make_valley(a) --> [100, 68, 55, 38, 12, *-82*, 12, 46, 66, 72]
The bottom is -82, left wing is [100, 68, 55, 38, 12]],
right wing is [*-82*, 12, 46, 66, 72].

a = [14,14,14,14,7,14]
make_valley(a) => [14, 14, 14, *7*, 14, 14]

a = [14,14,14,14,14]
make_valley(a) => [14, 14, *14*, 14, 14]

A counter-example:

a = [17, 17, 15, 14, 8, 7, 7, 5, 4, 4, 1]
A solution could be [17, 17, 15, 14, 8, 1, 4, 4, 5, 7, 7]
but the right wing [4, 4, 5, 7, 7] is much flatter than the left one 
[17, 17, 15, 14, 8].

Summing the differences between left and right wing:
(17-7)+(17-7)+(15-5)+(14-4)+(8-4) = 44

Consider the following solution:
[17, 15, 8, 7, 4, 1, 4, 5, 7, 14, 17]
Summing the differences between left and right wing:
(17-17)+(15-14)+(8-7)+(7-5)+(4-4) = 4
The right wing is nearly as steeply than the right one.

Note:

Don't modify the input arr in your code... or make a copy of it before
modifications.
*/

#include <iostream>
#include <vector>

class Valley
{
public:
    static std::vector<int> makeValley(std::vector<int> &arr);
};

// Solução
std::vector<int> Valley::makeValley(std::vector<int> &arr)
{
  int pos, max;
  bool flag(true);
  std::vector<int> sol, rigth{}, left{};
  
  sol = arr;
  while(!sol.empty()){  
    pos = 0;
    max = sol[pos];
    // Escolher maior valor
    for (unsigned i = 0; i < sol.size(); i++)
    {
      if (sol[i] >= max){
        max = sol[i];
        pos = i;
      }
    }
    // Excluir a posição do maior valor
    sol.erase(sol.begin() + pos);
    // Adicionar maior valor no vetor esquerdo ou direito
    if (flag == true && !sol.empty()) {
      left.push_back(max);
      flag = false;
    } else {
      rigth.push_back(max);
      flag = true;
    }
  }
  // Passar vetor esquerdo para vetor solução
  for (unsigned i = 0; i < left.size(); i++)
    sol.push_back(left[i]);
    
  // Passar vetor direito para vetor solução
  for (unsigned i = rigth.size(); i > 0; i--)
    sol.push_back(rigth[i - 1]);
  
  return sol;
}

// Imprime vetor
void printVector (std::vector<int> v){
	
	std::cout << "{ ";
	for (unsigned i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ",";
	std::cout << v[v.size() - 1] << " }";	
}

// Testes
void testequal(std::vector<int> ans, std::vector<int> sol)
{
	if (!sol.empty()) {
		printVector(ans);
		std::cout << " = ";
		printVector(sol);
		std::cout << " : " << std::boolalpha << (ans == sol) << "\n";
	} else
		std::cout << "{} = {}" << "\n";
}

static void dotest(std::vector<int> arr, std::vector<int> expected)
{
    testequal(Valley::makeValley(arr), expected);
}

int main()
    {
      std::vector<int> d, sol;
      d = { 17, 17, 15, 14, 8, 7, 7, 5, 4, 4, 1 };
      sol = { 17, 15, 8, 7, 4, 1, 4, 5, 7, 14, 17 };
      dotest(d, sol);

      d =  { 20, 7, 6, 2 };
      sol =  { 20, 6, 2, 7 };
      dotest(d, sol);
      
      d =  {  };
      sol =  {  };
      dotest(d, sol);

      d =  { 14, 10, 8 };
      sol =  { 14, 8, 10 };
      dotest(d, sol);
  
      return 0;
}
