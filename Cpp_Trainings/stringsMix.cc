/*
CODEWARS
https://www.codewars.com/kata/5629db57620258aa9d000014

"Strings Mix"
*/

#include <iostream>
#include <vector>

class Mix
{
public:
    static std::string mix(const std::string &s1, const std::string &s2);

private:
    static std::vector<std::string> frequencyChar(std::string s);
    static std::vector<std::string> sort(std::vector<std::string> v);
    static std::vector<std::string> compare(std::vector<std::string> v1, 
        std::vector<std::string> v2);
    static void printVector(std::vector<std::string> v, int c);
};

std::string Mix::mix(const std::string &s1, const std::string &s2)
{
	  std::string result = "";
    std::vector<std::string> v1, v2, vtemp;

    if (s1.empty() && s2.empty())
        return {};

	  // 1: contar a frequencia das letras minúsculas
    v1 = frequencyChar(s1);
    v2 = frequencyChar(s2);
    std::cout << "S1: " << s1 << std::endl;
    printVector(v1, 1);
    std::cout << "S2: " << s2 << std::endl;
    printVector(v2, 1);

    // 2: comparar e selecionar as frequencias máximas de cada letra
    vtemp = compare(v1, v2);
    std::cout << "Max:" << std::endl;
    printVector(vtemp, 2);

	  // 3: ordenar conforme tamanho e letra
    vtemp = sort(vtemp);
    std::cout << "Order:" << std::endl;
    printVector(vtemp, 2);

	  // 4: formatar saída em string
    if (!vtemp.empty()){
        for (int i = 0; i < vtemp.size() - 1; ++i)
            if(vtemp[i].size() > 2)
                result += vtemp[i] + '/';
        result += vtemp[vtemp.size()- 1];
    }
    return result;
}

std::vector<std::string> Mix::frequencyChar(std::string s)
{
    std::vector<std::string> freq(26);
    for (int i = 0; i < s.size(); ++i)
        if (s[i] >= 'a' && s[i] <= 'z')
            freq[int(s[i] - 97)] += s[i];
    return freq;
}

std::vector<std::string> Mix::sort(std::vector<std::string> v)
{
    bool swap(false);
    std::string temp;
    for (int i = 1; i < v.size(); ++i)
        for (int j = v.size() - 1; j >= i; --j){
            if (v[j - 1].size() <  v[j].size())
                swap = true;    // Verificar tamanho maior
            if ((v[j - 1].size() == v[j].size()) && (v[j - 1] > v[j]))
                swap = true;    // Sendo iguais, verificar ordem alfabética
            if (swap){
                temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
                swap = false;
            }
        }
    return v;
}

std::vector<std::string> Mix::compare(std::vector<std::string> v1,
 std::vector<std::string> v2)
{
    std::vector<std::string> max{};
    if (v1.empty() && v2.empty())
        return max;
    if (!v1.empty() && v2.empty())
        return v1;
    if (v1.empty() && !v2.empty())
        return v2;
    if (v1.size() == v2.size()){
        for (int i = 0; i < v1.size(); ++i){
            if (v1[i].size() < 2 && v2[i].size() < 2)
                continue;   // Descartar letras sem repetição
            if(v1[i].size() > v2[i].size())
                max.push_back("1:" + v1[i]);
            if(v1[i].size() < v2[i].size())
                max.push_back("2:" + v2[i]);
            if(v1[i].size() == v2[i].size())
                max.push_back("=:" + v1[i]);
        }
    }
    return max;
}

void Mix::printVector(std::vector<std::string> v, int c)
{
    if (!v.empty())
        for (int i = 0; i < v.size(); ++i)
        {
            switch (c)
            {        
            case 1: // imprimir frequências
                if (!v[i].empty()){
                    std::cout << "[" << char(97 + i);
                    std::cout << "] " << v[i].size() << " ";
                }
                break;
            case 2: // imprimir sequencia
                if (!v[i].empty())
                    std::cout << i << ": " << v[i] << std::endl;
                break;
            }
        }
   std::cout << std::endl;
}

// Testes
void testequal(std::string ans, std::string sol) {
  std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: " ;
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}

void dotest(const std::string &s1, const std::string &s2, std::string expected)
{
    testequal(Mix::mix(s1, s2), expected);
}

int main()
{
    std::string  s1, s2, sol;
    sol = "2:eeeee/2:yy/=:hh/=:rr";
    dotest("Are they here", "yes, they are here", sol);

    sol = "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg";
    dotest("looping is fun but dangerous", "less dangerous than coding", sol);

    s1 = "my&friend&Paul has heavy hats! &";
    s2 = "my friend John has many many friends &";
    sol = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
    dotest(s1, s2, sol);

    s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &";
    s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&";
    sol ="1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
    dotest(s1, s2, sol);

    s1="Are the kids at home? aaaaa fffff";
    s2="Yes they are here! aaaaa fffff";
    sol = "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh";
    dotest(s1, s2, sol);

    dotest("codewars", "codewars", "");

    // Outros testes
    dotest("zaaaanmmmhhh","zzzzaaanmmhh","1:aaaa/2:zzzz/1:hhh/1:mmm");
    dotest("aaazz", "", "1:aaa/1:zz");
    dotest("", "aaazz", "2:aaa/2:zz");
    dotest("", "", "");
    dotest("aabcc", "aabcc", "=:aa/=:cc");

    return 0;
}
