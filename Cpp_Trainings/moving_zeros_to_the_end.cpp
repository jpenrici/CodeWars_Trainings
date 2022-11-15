/*
CODEWARS
https://www.codewars.com/kata/52597aa56021e91c93000cb0

"Moving Zeros To The End"
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> move_zeroes(const vector<int> &input)
{

    vector<int> nums;
    vector<int> zeros;
    for (auto i : input) {
        if (i == 0) {
            zeros.push_back(0);
        }
        else {
            nums.push_back(i);
        }
    }
    nums.insert(nums.end(), zeros.begin(), zeros.end());

    return nums;
}

void testequal(vector<int> ans, vector<int> sol)
{
    bool result = true;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != sol[i]) {
            result = false;
            break;
        }
    }
    cout << boolalpha << result << '\n';
}

int main()
{
    testequal(move_zeroes(std::vector<int> {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}),
              std::vector<int> {1, 2, 1, 1, 3, 1, 0, 0, 0, 0});
    testequal(move_zeroes(std::vector<int> {0, 0, 0, 0, 0, 0}),
              std::vector<int> {0, 0, 0, 0, 0, 0});
    testequal(move_zeroes(std::vector<int> {1, 2, 5, 1, 5, 1, 5, 3, 2, 1}),
              std::vector<int> {1, 2, 5, 1, 5, 1, 5, 3, 2, 1});

    return 0;
};