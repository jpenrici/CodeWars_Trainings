/*
CODEWARS
https://www.codewars.com/kata/55cf3b567fc0e02b0b00000b

"Getting along with Integer Partitions"
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Imprimir vetor de combinações
template <class T1, class T2>
void printVector(std::vector<T1> v, T2 size)
{
  if (size >= v.size())
    size = v.size() - 1;
  if (v.empty())
    std::cout << "Empty!" << std::endl;
  else {
    std::cout << "{ ";
    for (unsigned i = 0; i < size; ++i)
      std::cout << v[i] << " , ";
    std::cout << v[size] << " }" << std::endl;
  }
}

template <class T>
void printVector(std::vector<T> v)
{
  printVector(v, v.size());
}

class IntPart
{
private:
  static std::vector<long long> vectorProd(long long n);
  static std::vector<long long> organize(std::vector<long long> v);
  static long long prod(std::vector<long long> v, long long size);
  static std::string div(long long dividend, int divisor);
public:
  static std::string part(long long n);
};

// Solução
std::string IntPart::part(long long n)
{
  int size(0);
  float avg(0), med(0);
  long long range(0), sum(0);
  std::vector<long long> v{};
  std::string sol;

  if(n < 1 || n > 50)
    return "(n integer, 1 <= n <= 50)!";

  v = vectorProd(n);
  //printVector(v);
  v = organize(v);
  //printVector(v);
  size = v.size();

  // Somatório do vetor multiplicação
  for (long long i = 0; i < size; ++i)
  {
    sum = sum + v[i];
  }

  // Preparar para saída em string
  // Intervalo
  sol = "Range: ";
  range = v[size - 1 ] - v[0];
  sol = sol + div(range, 0) + " Average: ";
  // Média
  sol = sol + div(sum, size) + " Median: ";
  // Mediana
  if(size % 2 == 0)
    sol = sol + div((v[(size / 2) - 1] + v[size / 2]), 2);
  else
    sol = sol + div(v[(size / 2)], 1);

  return sol;
}

// Formatar saída com 2 dígitos
std::string IntPart::div(long long dividend, int divisor)
{
  std::stringstream buffer;
  std::string result;

  if (divisor == 0)
  {
    buffer << dividend;
    result = buffer.str();
    buffer.str("");
    return result;
  }

  float rest = (dividend % divisor) / (float) divisor;
  int division = (dividend / divisor);
  buffer << division;
  result = buffer.str() + char(46);
  buffer.str("");
  if(rest == 0)
    result = result + "00";
  else 
  {
    rest = float(int((rest + 0.005) * 1000) / 10);  // Arredondar resto
    if (rest < 10)
      result = result + "0";
    buffer << rest;
    result += buffer.str();
    buffer.str("");
  }

  return result;
}

// Particiona e retorna o vetor de multiplicação
std::vector<long long> IntPart::vectorProd(long long n)
{
  std::vector<long long> combination{}, mult{};
  long long k(1), x(0), y(n - 1), l(0); 
  int counter(0);

  for (long long i = 0; i <= n; ++i)
    combination.push_back(0);
  while (k != 0)
  {
    x = combination[k - 1] + 1;
    k -= 1;
    while (2 * x <= y)
    {
      combination[k] = x;
      y -= x;
      k += 1;
    }
    l = k + 1;
    while (x <= y)
    {
      combination[k] = x;
      combination[l] = y;
      counter++;
      //printVector(combination, k + 1);
      mult.push_back(prod(combination, k + 2));
      x += 1;
      y -= 1;
    }
    combination[k] = x + y;
    y = x + y - 1;
    counter++;
    //printVector(combination, k);
    mult.push_back(prod(combination, k + 1));
  }
  std::cout << "enum(" << n << ")\tcombinations: " << counter << std::endl;

  return mult;
}

// Multiplicar os números dentro da combinação
long long IntPart::prod(std::vector<long long> v, long long size)
{
  long long mult(1);
  if (size >= v.size())
    size = v.size() - 1;
  for (long long i = 0; i < size; ++i)
    mult = mult * v[i];
  return mult;
}

// Organizar vetor
std::vector<long long> IntPart::organize(std::vector<long long> v)
{
  long long temp;
  std::vector<long long> vorg;
  // Ordenar e eliminar repetições
  for (long i = v.size() - 1; i >= 1; i--)
    for (long j = 0; j < i; j++){
      if (v[j] > v[j + 1]){
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
      if (v[j] == v[j + 1]){
        v[j] = -1;  // Marcar repetição
      }
    }
  for (long long i = 0; i < v.size(); ++i)
  {
    if(v[i] != -1)
      vorg.push_back(v[i]);
  }

    return vorg;
}

void testequal(std::string ans, std::string sol) {
  std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: ";
  std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
  testequal(IntPart::part(1), "Range: 0 Average: 1.00 Median: 1.00");
  testequal(IntPart::part(2), "Range: 1 Average: 1.50 Median: 1.50");
  testequal(IntPart::part(3), "Range: 2 Average: 2.00 Median: 2.00");
  testequal(IntPart::part(4), "Range: 3 Average: 2.50 Median: 2.50");
  testequal(IntPart::part(5), "Range: 5 Average: 3.50 Median: 3.50");
  testequal(IntPart::part(6), "Range: 8 Average: 4.75 Median: 4.50");
  testequal(IntPart::part(8), "Range: 17 Average: 8.29 Median: 7.50");
  testequal(IntPart::part(10), "Range: 35 Average: 15.00 Median: 14.00");
  testequal(IntPart::part(12), "Range: 80 Average: 27.08 Median: 22.50");
  testequal(IntPart::part(26), "Range: 13121 Average: 1500.90 Median: 625.00");
  testequal(IntPart::part(30), "Range: 59048 Average: 4764.89 Median: 1538.00");
  testequal(IntPart::part(40), "Range: 2125763 Average: 85158.49 Median: 14250.00");

  return 0;
}
