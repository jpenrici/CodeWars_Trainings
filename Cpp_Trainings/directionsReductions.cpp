/*
CODEWARS
https://www.codewars.com/kata/550f22f4d758534c1100025a

"Directions Reduction"

Once upon a time, on a way through the old wild west,…

… a man was given directions to go from one point to another.
The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH"
and "SOUTH" are opposite, "WEST" and "EAST" too. Going to one direction
and coming back the opposite direction is a needless effort. Since this
is the wild west, with dreadfull weather and not much water, it's
important to save yourself some energy, otherwise you might die of
thirst!
How I crossed the desert the smart way.

The directions given to the man are, for example, the following:
["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"].
or
{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };

or (haskell)
[North, South, South, East, West, North, West]
You can immediatly see that going "NORTH" and then "SOUTH" is not
reasonable, better stay to the same place! So the task is to give to
the man a simplified version of the plan. A better plan in this case
is simply:

["WEST"] or { "WEST" }

or (haskell)
[West] or (rust)[WEST];

Other examples:

In ["NORTH", "SOUTH", "EAST", "WEST"], the direction "NORTH" + "SOUTH"
is going north and coming back right away. What a waste of time! Better
to do nothing.

The path becomes ["EAST", "WEST"], now "EAST" and "WEST" annihilate each
other, therefore, the final result is [] (nil in Clojure).

In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and
"SOUTH" are not directly opposite but they become directly opposite
after the reduction of "EAST" and "WEST" so the whole path is reducible
to ["WEST", "WEST"].

Task
Write a function dirReduc which will take an array of strings and
returns an array of strings with the needless directions removed
(W<->E or S<->N side by side).

The Haskell version takes a list of directions with data
Direction = North | East | West | South. The Clojure version returns nil
when the path is reduced to nothing. The Rust version takes a slice of
enum Direction {NORTH, SOUTH, EAST, WEST}.

Examples

dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"])
=> ["WEST"]
dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"])
=> []

See more examples in "Example Tests"
Note

All paths can't be made simpler.
The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible.
"NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not
directly opposite of each other and can't become such. Hence the result
path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};

// Solução
std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr){
	
	unsigned int pos;
	std::vector<std::string> sol = arr;
	std::map<std::string, std::string> DIRECTION;

	DIRECTION["NORTH"] = "SOUTH";
	DIRECTION["SOUTH"] = "NORTH";
	DIRECTION["EAST"]  = "WEST";
	DIRECTION["WEST"]  = "EAST";
	
	pos = 0;
	while(pos + 1 < sol.size() && !sol.empty()) {
		for (std::map<std::string, std::string>::iterator d = DIRECTION.begin(); d != DIRECTION.end(); ++d ) {
			if ((sol[pos] == d->first) && (sol[pos + 1] == d->second)) {
				std::cout << sol[pos] << " [" << pos << "] <-> ";
				std::cout << sol[pos + 1] << " [" << pos + 1 << "]\n";
				sol.erase(sol.begin() + pos);
				sol.erase(sol.begin() + pos);
				pos = -1;
				break;
			}		
		}
		pos++;
	}
	
	if (sol.empty())
		sol = {" "};
		// sol = {};	// Plataforma
		
	return sol;
}

// Imprime vetor
void printVector (std::vector<std::string> v){
	
	std::cout << "{ ";
	for (unsigned int i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ",";
	std::cout << v[v.size() - 1] << " }";	
}

// Teste de Igualdade
void testequal(std::vector<std::string> ans, std::vector<std::string> sol)
{
	printVector(ans);
	std::cout << " = ";
	printVector(sol);
	std::cout << " : " << std::boolalpha << (ans == sol) << std::endl;
}

// Testes
int main()
{
	// Sample Tests
  std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
	printVector(d1);
	std::cout << std::endl;    
	std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
	std::vector<std::string> sol1 = {"WEST"};
	testequal(ans1, sol1);

	std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
	std::cout << std::endl;
	printVector(d2);
	std::cout << std::endl;
	std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
	std::vector<std::string> sol2 = {"NORTH"};
	testequal(ans2, sol2);
	
	// Extras
	std::vector<std::string> d3 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"};
	std::cout << std::endl;	
	printVector(d3);
	std::cout << std::endl;	
	std::vector<std::string> ans3 = DirReduction::dirReduc(d3);
	std::vector<std::string> sol3 = {" "};
	testequal(ans3, sol3);
	
	std::vector<std::string> d4 = {"NORTH"};
	std::cout << std::endl;
	printVector(d4);
	std::cout << std::endl;	
	std::vector<std::string> ans4 = DirReduction::dirReduc(d4);
	std::vector<std::string> sol4 = {"NORTH"};
	testequal(ans4, sol4);
	
	return 0;
}
