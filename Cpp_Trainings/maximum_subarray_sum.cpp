/*
CODEWARS
https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c

"Maximum subarray sum"
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int maxSequence(const vector<int> &arr)
{

    if (arr.empty()) {
        return 0;
    }

    auto result = minmax_element(arr.begin(), arr.end());
    auto minimum = arr[result.first - arr.begin()];
    auto maximum = arr[result.second - arr.begin()];
    if (minimum < 0 && maximum < 0) {
        return 0;
    }
    if (minimum >= 0 && maximum >= 0) {
        return accumulate(arr.begin(), arr.end(), 0);
    }

    int sum = arr[0];
    int maxSum = sum;
    for (int i = 1; i < arr.size(); i++) {
        sum = max(arr[i], sum + arr[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

void testequal(int ans, int sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(maxSequence({}), 0);
    testequal(maxSequence({0}), 0);
    testequal(maxSequence({-1, -2, -3}), 0);
    testequal(maxSequence({0, 1, 2, 3}), 6);
    testequal(maxSequence({3, -1, 6}), 8);
    testequal(maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    testequal(maxSequence({7, 4, 11, -11, 39, 36, 10, -6, 37, -10, -32, 44, -26, -34, 43, 43}), 155);

    return 0;
};
