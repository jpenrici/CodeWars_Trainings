/*
CODEWARS - Estudo de Solução
https://www.codewars.com/kata/58602cd3ef06546bb7000152

"Tuple sum"
*/

#include <tuple>
#include <string>
#include <vector>
#include <iostream>

using namespace std::string_literals;

// Visualizar
template<typename T>
void print(T t) { std::cout << t << char(32); }

template<typename T> 
void print(const std::vector<T> v) { std::cout << "Vetor" << char(32); }

template<typename T>
bool is_valid(const T& t)
{
    if (typeid(int) == typeid(T)) return true;
    if (typeid(double) == typeid(T)) return true;
    return false;
}

// Solução
template<typename T>
void add(const T& t, double& sum)
{
  const void* val = &t;
  if (typeid(double) == typeid(T)) {
      const double* val_double = (double*)val;
      sum += *val_double;
  }
  else if (typeid(int) == typeid(T)) {
      const int* val_int = (int*)val;
      sum += *val_int;
  }
};

template<typename T, std::size_t N>
struct SumNum {
    static void calc(const T& t, double& sum)
    {
        SumNum<T, N-1>::calc(t, sum);
        auto item = std::get<N-1>(t);
        print(item);
        std::cout << std::boolalpha << is_valid(item) << '\n';
        add(item, sum);
    }
};

template<typename T>
struct SumNum<T, 1> {
    static void calc(const T& t, double& sum)
    {
        auto item = std::get<0>(t);
        print(item);
        std::cout << std::boolalpha << is_valid(item) << '\n';
        add(item, sum);     
    }
};

template <typename... Ts> 
double tuple_sum(const std::tuple<Ts...>& tpl) {
    double sum(0);
    SumNum<decltype(tpl), sizeof...(Ts)>::calc(tpl, sum);
    return sum;
}

// Teste
void testequal(double  ans, double  sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << "(ans = sol) " << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    // Teste Visualização
    // print("test");
    // print("string_literals"s);
    // print(-10);
    // print(3.64);
    // print(std::vector<int>{1, 2, 3});
    // std::cout << '\n';

    // Teste Codewars
    std::cout << "Itens Tuple 1:\n";
    testequal(tuple_sum(std::make_tuple(3.14, 42, 'a', "Hello", "World"s,
        std::vector<int>{1, 2, 3})), 45.14);
    std::cout << '\n';

    std::cout << "Itens Tuple 2:\n";
    testequal(tuple_sum(std::make_tuple(3.14, 42, 10, 'a', "Hello", "World"s)),
        55.14);

    return 0;
};
