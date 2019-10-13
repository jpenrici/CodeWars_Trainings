/*
CodeWars
https://www.codewars.com/kata/battleship-field-validator/cpp

"Battleship field validator"
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int ship_length = 0;
bool invalid = false;
string direction = "";

void view_vector(vector< vector<int> >& field);

void dfs(vector< vector<int> >& field, int i, int j, string current_direction)
{
    if (i < 0 || j < 0) return;
    if (i >= field.size() || j >= field[0].size()) return;
    if (field[i][j] != 1) return;

    if (current_direction != direction) invalid = true;

    ship_length += 1;
    field[i][j] = 2;
    dfs(field, i - 1, j, "up");
    dfs(field, i + 1, j, "down");
    dfs(field, i, j - 1, "left");
    dfs(field, i, j + 1, "right");
    dfs(field, i - 1, j - 1, "up left");
    dfs(field, i - 1, j + 1, "upright");
    dfs(field, i + 1, j - 1, "down left");
    dfs(field, i + 1, j + 1, "down right");
}

bool validate_battlefield(vector<vector<int> > field) {

    // view_vector(field);

    if (field.size() != 10 || field.size() != 10) return false;

    int sum = accumulate(field.begin(), field.end(), 0,
        [] (int i, const vector<int>& v) {
            return i += accumulate(v.begin(), v.end(), 0);
        });

    if (sum == 0) return true;
    if (sum != 20) return false;

    vector<int> ships_rest{4, 3, 2, 1};
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[i].size(); ++j) {
            if (field[i][j] == 1) {
                if (field[i][j + 1] == 1) direction = "right";
                else direction = "down";
                dfs(field, i, j, direction);
                if (invalid) return false;  
                if (ship_length > 4) return false;
                if (ship_length > 0) {
                    ships_rest[ship_length - 1]--;
                    if (ships_rest[ship_length - 1] < 0) return false;
                }
                ship_length = 0;
            }
        }
    }
    return (accumulate(ships_rest.begin(), ships_rest.end(), 0) == 0);
}

void testequal(size_t line, bool ans, bool sol)
{
    cout << "Line [" << line << "]: " << boolalpha << (ans == sol) << '\n';
}

void test()
{
    // Zeros
    testequal(__LINE__, validate_battlefield(vector< vector<int> > {
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }), true); 

    // ones
    testequal(__LINE__, validate_battlefield(vector< vector<int> > {
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    }), false);

    // others
    testequal(__LINE__, validate_battlefield(vector< vector<int> > {
      vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
      vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }), true);

    testequal(__LINE__, validate_battlefield(vector< vector<int> > {
      vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0}, 
      vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0}, 
      vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
      vector<int> {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
      vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
      vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }), false);

    testequal(__LINE__, validate_battlefield(vector< vector<int> > {
      vector<int> {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      vector<int> {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      vector<int> {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }), false);

    testequal(__LINE__, validate_battlefield(vector< vector<int> > {
        vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        vector<int> {1, 1, 0, 0, 1, 1, 1, 0, 1, 0},
        vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        vector<int> {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        vector<int> {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }), false);
}

void view_vector(vector< vector<int> > &field) {
    for (int i = 0; i < field.size(); ++i)
    {
        for (int j = 0; j < field[i].size(); ++j)
        {
            cout << field[i][j] << " ,";
        }
        cout << "" << '\n';
    }
}

int main()
{
    test();
    return 0;
}