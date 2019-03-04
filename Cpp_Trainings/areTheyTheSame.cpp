/*
CODEWARS
https://www.codewars.com/kata/550498447451fbbd7600041c

"Are they the "same"?"
*/

#include <iostream>
#include <vector>

using namespace std;

// Imprimir vetor
template <class T>
void printVector(std::vector<T> v)
{
    if (v.empty())
        std::cout << "Empty!" << std::endl;
    else {
        std::cout << "{ ";
        for (unsigned i = 0; i < v.size(); ++i)
            std::cout << v[i] << " , ";
        std::cout << v[v.size()] << " }" << std::endl;
    }
}

class Same {
    public :static bool comp(vector<int>, vector<int>);
};

// Solução
bool Same::comp(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
    {
       for (int j = 0; j < b.size(); ++j)
       {
        if(b[j] == a[i] * a[i]){
            b.erase(b.begin() + j);
            break;
           }
       }
    }
    if (b.empty())
        return true;

    return false;
}

// Testes
int main()
{
    static const int arr1[] = {121, 144, 19, 161, 19, 144, 19, 11};
    vector<int> a1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    static const int arr2[] = {11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19};
    vector<int> b2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    bool r = Same::comp(a1, b2); // true

    printVector(a1);
    printVector(b2);
    cout << boolalpha << r << endl;    

    static const int arr3[] = { 0 , -14 , 191 , 161 , 19 , 144 , 195 , -1 };
    vector<int> a3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
    static const int arr4[] = { 1 , 0 , 196 , 36481 , 25921 , 361 , 20736 , 38025 };
    vector<int> b4 (arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
    r = Same::comp(a3, b4); // true

    printVector(a3);
    printVector(b4);
    cout << boolalpha << r << endl;

    return 0;  
}
