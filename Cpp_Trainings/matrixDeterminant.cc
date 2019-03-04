/*
CODEWARS - Estudo de Solução
https://www.codewars.com/kata/52a382ee44408cea2500074c

"Matrix Determinant"
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string printMatrix (vector<vector<long long>> m){
    string s;
    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 0; j < m[i].size(); ++j)
            s += to_string(m[i][j]) + " ";
        s += "\n";
    }
    return s;
}

vector< vector<long long>> submatrix(vector<vector<long long>> m, int order, int i, int j)
{
    int r(0), c;
    vector< vector<long long>> subm (order, vector<long long> (order - 1, 0));
    
    for(int p = 0; p < order; p++) 
    {
        if(p == i) continue;
        c = 0;
        for(int q = 0; q < order; q++) {
            if(q == j) continue;
            subm[r][c++] = m[p][q];
        }
        r++;
    }
    return subm;
}

long long det(vector< vector<long long>> m, int order)
{
    if (m.empty()) return 0;
    if (order == 1) return m[0][0];
    if (order == 2) return ((m[0][0] * m[1][1]) - (m[1][0] * m[0][1]));

    int result(0);
    for(int i = 0; i < order; i++)
        result = result + static_cast<long long>(pow(- 1.0,(long long)i)) * m[i][0] * det(submatrix(m, order, i, 0), order - 1);
    return result;
}

long long determinant(vector< vector<long long>> m) 
{
    int order = m.size();
    return det(m, order);
}

void testequal(vector<vector<long long>> matrix, long long sol)
{
    // Print Vector
    cout << "Matrix [" << matrix.size() << ",";
    cout << matrix[0].size() << "]:" << endl;
    cout << printMatrix(matrix);
    long long ans = determinant(matrix);
    cout << "ans: " << ans << "\nsol: " << sol << endl;
    cout << boolalpha << (ans == sol) << endl;
}

int main()
{
    testequal(vector< vector<long long> > {
      vector<long long> {1}
    }, 1);
    testequal(vector< vector<long long> > {
      vector<long long> {1, 3},
      vector<long long> {2, 5}
    }, -1);
    testequal(vector< vector<long long> > {
      vector<long long> {2, 5, 3},
      vector<long long> {1, -2, -1},
      vector<long long> {1, 3, 4}
    }, -20);

    return 0;
};
