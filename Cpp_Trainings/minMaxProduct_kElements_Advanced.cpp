/*
CodeWars
https://www.codewars.com/kata/5b05867c87566a947a00001c

"Minimum and Maximum Product of k Elements - Advanced"
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void view(std::vector<int32_t> in, int k);

std::pair<std::int64_t, std::int64_t>
basic(std::vector<std::int32_t> arr, int k)
{
    int64_t minimum(1), maximum(1);
    int n = arr.size() - 1;
    for (int i = 0; i < k; ++i) {
        minimum *= arr[i];
        maximum *= arr[n - i];
    }
    if (maximum < minimum) return {maximum, minimum};
    return {minimum, maximum};
}

std::pair<std::int64_t, std::int64_t>
special(std::vector<std::int32_t> arr, int k)
{
    int n = arr.size() - 1;
    std::vector<int64_t> products;

    for (int i = 0; i < k; ++i) {
        int64_t product(1);
        for (int j = 0; j < k; ++j) {
            if (j < i) product *= arr[j];
            else product *= arr[n - j + i];
        }
        products.push_back(product);
    }

    std::pair<std::int64_t, std::int64_t> other = basic(arr, k);
    products.push_back(other.first);
    products.push_back(other.second);
    std::sort(products.begin(), products.end());

    return {products.front(),products.back()};
}

std::pair<std::int64_t, std::int64_t>
find_min_max_product(std::vector<std::int32_t> arr, int k)
{
    // exceptions
    if (k < 1) throw std::exception();
    if (k > arr.size()) throw std::exception();
    if (arr.empty()) throw std::exception();

    // view
    view(arr, k);

    // basic
    if (arr.size() == 1) return {arr[0], arr[0]};

    // elements > 1
    sort(arr.begin(), arr.end());
    
    // k = 1
    if (k == 1) return {arr.front(), arr.back()};

    // Zeros
    if (arr.front() == 0 && arr.back() == 0) return {0,0};

    // Positives
    if (arr.front() >= 0) return basic(arr, k);

    // Negatives + Zeros
    if (arr.front() < 0 && arr.back() <= 0) return basic(arr, k);

    // Others
    return special(arr, k);
}

void view(std::vector<int32_t> in, int k)
{
    std::cout << "K: " << k << "\narr: ";
    for(int32_t i: in)
        std::cout << char(32) << i;
    std::cout << '\n';
}

void testequal(size_t line, std::pair<std::int64_t, std::int64_t> pair,
    std::vector<int> v)
{
    std::cout << "Line [" << line << "]: " << "Min: " << pair.first << '\t'
        << "Max: " << pair.second << '\t' << std::boolalpha
        << (v[0] == pair.first && v[1] == pair.second) << '\n';
}

int main()
{
    std::cout << "\n// Zeros\n";
    testequal(__LINE__, find_min_max_product({0}, 1),{0,0});                            
    testequal(__LINE__, find_min_max_product({0, 0, 0}, 2),{0,0});              

    std::cout << "\n// Positives\n";
    testequal(__LINE__, find_min_max_product({ 0, 1, 2}, 1),{0,2});         
    testequal(__LINE__, find_min_max_product({ 0, 1, 2}, 2),{0,2});         
    testequal(__LINE__, find_min_max_product({ 0, 1, 2}, 3),{0,0});         
    testequal(__LINE__, find_min_max_product({ 1, 2, 3}, 1),{1,3}); 
    testequal(__LINE__, find_min_max_product({ 1, 2, 3}, 2),{2,6});  
    testequal(__LINE__, find_min_max_product({ 1, 2, 3}, 3),{6,6}); 
    testequal(__LINE__, find_min_max_product({1, 2, 3, 4}, 1),{1,4});   
    testequal(__LINE__, find_min_max_product({1, 2, 3, 4}, 2),{2,12});      
    testequal(__LINE__, find_min_max_product({1, 2, 3, 4}, 3),{6,24});      
    testequal(__LINE__, find_min_max_product({1, 2, 3, 4}, 4),{24,24});
    testequal(__LINE__, find_min_max_product({ 0, 1, 2, 3, 4}, 1),{0,4});
    testequal(__LINE__, find_min_max_product({ 0, 1, 2, 3, 4}, 2),{0,12});
    testequal(__LINE__, find_min_max_product({ 0, 1, 2, 3, 4}, 3),{0,24});
    testequal(__LINE__, find_min_max_product({ 0, 1, 2, 3, 4}, 4),{0,24});
    testequal(__LINE__, find_min_max_product({ 0, 1, 2, 3, 4}, 5),{0,0});
    
    std::cout << "\n// Positive with multiple zeros\n";
    testequal(__LINE__, find_min_max_product({ 0, 0, 0, 0, 0, 0, 0, 0, 4}, 4),{0,0});   
    testequal(__LINE__, find_min_max_product({ 0, 0, 0, 0, 0, 0, 0, 0, 4}, 1),{0,4});   
    testequal(__LINE__, find_min_max_product({ 0, 0, 0, 0, 0, 0, 0, 3, 4}, 2),{0,12});  
    testequal(__LINE__, find_min_max_product({ 0, 0, 0, 0, 0, 1, 2, 3, 4}, 4),{0,24});

    std::cout << "\n// Negatives\n";
    testequal(__LINE__, find_min_max_product({-3, -2, -1}, 1),{-3,-1});
    testequal(__LINE__, find_min_max_product({-3, -2, -1}, 2),{2,6});
    testequal(__LINE__, find_min_max_product({-3, -2, -1}, 3),{-6,-6});

    std::cout << "\n// Negatives and zeros\n";
    testequal(__LINE__, find_min_max_product({-2, -1, 0}, 1),{-2,0});
    testequal(__LINE__, find_min_max_product({-2, -1, 0}, 2),{0,2});
    testequal(__LINE__, find_min_max_product({-2, -1, 0}, 3),{0,0});    
    testequal(__LINE__, find_min_max_product({-2, -1, 0, 0}, 1),{-2,0});    
    testequal(__LINE__, find_min_max_product({-2, -1, 0, 0}, 2),{0,2}); 
    testequal(__LINE__, find_min_max_product({-2, -1, 0, 0, 0, 0}, 3),{0,0});   
    testequal(__LINE__, find_min_max_product({-2, -1, -1, 0, 0, 0}, 3),{-2,0}); 
    testequal(__LINE__, find_min_max_product({-2, -1, -1, -1, 0, 0}, 4),{0,2}); 
    testequal(__LINE__, find_min_max_product({-2, -2, -1, -1, -1, 0}, 4),{0,4});    

    std::cout << "\n// Others\n";
    testequal(__LINE__, find_min_max_product({-1, 0, 1}, 1),{-1, 1});
    testequal(__LINE__, find_min_max_product({-2, -1, 0, 1}, 2),{-2, 2});
    testequal(__LINE__, find_min_max_product({-2, -1, 0, 1, 2}, 3),{-4, 4});
    testequal(__LINE__, find_min_max_product({-3, -2, -1, 0, 1, 2, 3, 4}, 1),{-3, 4});
    testequal(__LINE__, find_min_max_product({-3, -2, -1, 0, 1, 2, 3, 4}, 2),{-12, 12});
    testequal(__LINE__, find_min_max_product({-3, -2, -1, 0, 1, 2, 3, 4}, 7),{-144, 0});
    testequal(__LINE__, find_min_max_product({-1, 1, 2}, 1),{-1, 2});
    testequal(__LINE__, find_min_max_product({-1, 1, 2}, 2),{-2, 2});
    testequal(__LINE__, find_min_max_product({-1,-2, 1}, 2),{-2, 2});

    std::cout << "\n// CodeWars\n";
    // k = 1: -3, 7
    testequal(__LINE__, find_min_max_product({1, -2, -3, 4, 6, 7}, 1), {-3, 7});

    // k = 2: -3 * 7 = -21, 6 * 7 = 42
    testequal(__LINE__, find_min_max_product({1, -2, -3, 4, 6, 7}, 2), {-21, 42});

    // k = 3: -3 * 6 * 7 = -126, 4 * 6 * 7 = 168
    testequal(__LINE__, find_min_max_product({1, -2, -3, 4, 6, 7}, 3), {-126, 168});

    testequal(__LINE__, find_min_max_product({0, -1, -2, -3, -4}, 2), {0, 12});
    testequal(__LINE__, find_min_max_product({-1, -2, -3, -4}, 2), {2, 12});
    testequal(__LINE__, find_min_max_product({-20, -35, -60, 4, 20, 29}, 2), {-1740, 2100});
    testequal(__LINE__, find_min_max_product({20, -39, 97, 98, -48, -77, 63}, 4), {-46113606, 35134176});

    return 0;
}
