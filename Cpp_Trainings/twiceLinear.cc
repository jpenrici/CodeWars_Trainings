/*
CODEWARS
https://www.codewars.com/kata/5672682212c8ecf83e000050

"Twice linear"
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

inline void printVector (std::vector<int> v)
{
    std::cout << "{ ";
    for(int value: v)
        std::cout << value << " ";
    std::cout << "}" << std::endl;
}

class DoubleLinear
{
public:
    static int dblLinear(int n);
};

int DoubleLinear::dblLinear(int n)
{
    std::map<int, bool> map_sequence;
    std::vector<int> sequence;

    map_sequence.insert(std::pair<int,bool>(1, false));

    while (sequence.size() <= n + 1){
        for(std::map<int, bool>::iterator it = map_sequence.begin(); it != map_sequence.end(); ++it){
            // std::cout << "map: {" << it->first << ", " << it->second << "}" << std::endl;
            int x = it->first;
            if (not it->second){
                map_sequence.insert(std::pair<int,bool>(x * 2 + 1, false));
                map_sequence.insert(std::pair<int,bool>(x * 3 + 1, false));
                sequence.push_back(x);
                map_sequence.erase(x);
                break;
            }
        }
    }
    std::sort (sequence.begin(), sequence.end());

    // printVector(sequence);

    return sequence[n];
}

void testequal(int ans, int sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

void dotest(int n, int expected)
{
    testequal(DoubleLinear::dblLinear(n), expected);
}

int main()
{
    dotest(10, 22);
    dotest(20, 57);
    dotest(30, 91);
    dotest(50, 175);

    return 0;
};
