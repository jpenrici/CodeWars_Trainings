/*
CODEWARS
https://www.codewars.com/kata/5270d0d18625160ada0000e4

"Greed is Good"
*/

#include <iostream>
#include <vector>

using namespace std;

int score(const vector<int> &dice)
{

    vector<int> counter {0, 0, 0, 0, 0, 0, 0};
    int sum = 0;

    for (auto i : dice) {
        counter[i]++;
    }

    // Three 1's => 1000 points
    // One   1   =>  100 points
    if (counter[1] < 3) {
        sum += counter[1] * 100;
    }
    else if (counter[1] >= 3) {
        sum += 1000 + (counter[1] - 3) * 100;
    }

    // Three 6's =>  600 points
    if (counter[6] >= 3) {
        sum += 600;
    }

    // Three 5's =>  500 points
    // One   5   =>   50 point
    if (counter[5] < 3) {
        sum += counter[5] * 50;
    }
    else if (counter[5] >= 3) {
        sum += 500 + (counter[5] - 3) * 50;
    }

    // Three 4's =>  400 points
    if (counter[4] >= 3) {
        sum += 400;
    }

    // Three 3's =>  300 points
    if (counter[3] >= 3) {
        sum += 300;
    }

    // Three 2's =>  200 points
    if (counter[2] >= 3) {
        sum += 200;
    }

    return sum;
}

void testequal(int ans, int sol)
{
    cout << "ans: " << ans << "\nsol: " << sol << '\n'
         << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(score({2, 3, 4, 6, 2}), 0);
    testequal(score({2, 4, 4, 5, 4}), 450);
    testequal(score({5, 1, 3, 4, 1}), 250);
    testequal(score({1, 1, 1, 3, 1}), 1100);
    testequal(score({3, 3, 3, 3, 3}), 300);
    testequal(score({4, 2, 2, 2, 2}), 200);
    testequal(score({5, 5, 5, 3, 3}), 500);
    testequal(score({5, 5, 6, 5, 3}), 500);

    return 0;
};
