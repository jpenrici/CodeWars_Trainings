/*
CODEWARS
https://www.codewars.com/kata/536a155256eb459b8700077e

"The Clockwise Spiral"
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > create_spiral(int n)
{
    if (n <= 0) {
        return {};
    }

    vector<vector<int> > matrix(n, vector<int>(n, 0));

    auto insert_value = [](int r, int c, vector<vector<int> > &m, int value) {
        int size = m.size();
        if (r >= 0 && r < size && c >= 0 && c < size) {
            if (m[r][c] == 0) {
                m[r][c] = value;
                return true;
            }
        }
        return false;
    };

    int num = 1;
    int row = 0;
    int col = 0;
    int cells = n * n;

    while (num <= cells) {

        while (insert_value(row, col, matrix, num)) {
            num++;
            col++;
        }

        row++;
        col = n - 1;
        while (insert_value(row, col, matrix, num)) {
            num++;
            row++;
        }

        row = n - 1;
        col--;
        while (insert_value(row, col, matrix, num)) {
            num++;
            col--;
        }

        row--;
        col++;
        while (insert_value(row, col, matrix, num)) {
            num++;
            row--;
        }

        row++;
        col++;
        n--;
    }

    return matrix;
}

template<typename T>
void view_vector(std::vector<T> v)
{
    switch (v.size()) {
    case 0:
        break;
    case 1:
        std::cout << v[0] << '\n';
        break;
    default:
        for (int i = 0; i < v.size() - 1; ++i) {
            std::cout << v[i] << char(32);
        }
        std::cout << v[v.size() - 1] << '\n';
    }
}

void testequal(vector<vector<int> > ans, vector<vector<int> > sol)
{
    bool check = true;
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            if (ans[i][j] != sol[i][j]) {
                check = false;
                break;
            }
        }
    }

    for (auto i = 0; i < sol.size(); i++) {
        view_vector(sol[i]);
    }
    cout << boolalpha << check << '\n';
}

int main()
{
    testequal(create_spiral(-1), vector<vector<int> > {
        {}
    });
    testequal(create_spiral(1), vector<vector<int> > {
        {1}
    });
    testequal(create_spiral(3), vector<vector<int> > {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    });
    testequal(create_spiral(4), vector<vector<int> > {
        { 1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    });
    testequal(create_spiral(5), vector<vector<int> > {
        { 1, 2, 3, 4, 5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11, 10, 9}
    });

    return 0;
};