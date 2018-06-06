/*
CODEWARS
https://www.codewars.com/kata/58dea43ff98a7e2124000169

"Divide integers as strings"
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string validate(string num)
{
    while(num.length() > 0) {
        if (num[0] != '0') return num;
        else num.erase(0,1);
    }
    return "0";
}

int compare(string num1, string num2)
{
    num1 = validate(num1);
    num2 = validate(num2);
    if (num1.length() > num2.length()) return  1;
    if (num1.length() < num2.length()) return -1;    
    for (int i = 0; i < num1.length(); ++i) {
        if (num1[i] < num2[i]) return -1;       // num1 < num2
        else if (num1[i] > num2[i]) return 1;   // num1 > num2
    }
    return 0;                                   // num1 = num2
}

// num * [0-9]
string multiply(string num, int digit)
{
    if ((digit <= 0) || (digit > 9)) return "0";
    num = validate(num);

    // cálculo rápido
    // if (num.length() <= 16) return to_string(stoll(num,nullptr,10)*digit);  

    // cálculo lento
    int carry = 0;
    string result = "";
    for (int i = num.size()-1; i >= 0; i--) {
        int sum = ((num[i]-'0')*digit)+carry;
        carry = sum/10;
        if (i != 0) result = to_string(sum%10)+result;
        else result = to_string(sum)+result;
    }
    return result;
}

string difference(string num1, string num2)
{
    // igualar tamanhos das strings
    while(num1.length() < num2.length()) num1 = '0'+num1;
    while(num2.length() < num1.length()) num2 = '0'+num2;

    int test = compare(num1,num2);
    if (test == 0) return "0";      // num1 = num2, resto = 0
    if (test < 0) swap(num1,num2);  // num1 < num2, swap

    // cálculo rápido
    // if (num1.length() <= 16)
    //  return to_string(stoll(num1,nullptr,10)-stoll(num2,nullptr,10));

    // cálculo lento
    int carry = 0;
    string result = "";
    int n1 = num1.length();
    int n2 = num2.length();
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    for (int i = 0; i < n2; ++i) {
        int sub = (num1[i]-'0')-(num2[i]-'0')-carry;
        if (sub < 0){
            sub = sub+10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result.push_back(sub+'0');
    }
    for (int i = n2; i < n1; ++i) {
        int sub = (num1[i]-'0')-carry;
        carry = 0;
        result.push_back(sub+'0');
    }
    reverse(result.begin(),result.end());
    return result;
}

// Solução
vector<string> divide_strings(string dividend, string divisor)
{
    dividend = validate(dividend);
    divisor = validate(divisor);

    // cálculo rápido
    if (dividend == "0") return {"0","0"};
    if (divisor == "0") return {"0",dividend};
    // if (dividend.length() <= 16) {
    //  return {to_string(stoll(dividend,nullptr,10)/stoll(divisor,nullptr,10)),
    //      to_string(stoll(dividend,nullptr,10)%stoll(divisor,nullptr,10))};
    // }
    int test = compare(dividend,divisor);
    if (test < 0) return {"0",dividend};    // a < b
    if (test == 0) return {"1","0"};        // a = b

    // cálculo lento
    string quotient = "";
    string remainder = dividend.substr(0,divisor.length());  // resto = sub-a
    dividend = dividend.erase(0,divisor.length());           // atualizar a

    // inicializa múltiplos de b
    vector<string> multiple{"0",divisor,"0","0","0","0","0","0","0","0",
        divisor+'0'};

    // dividir
    while(!dividend.empty()) {

        // dividendo = (quociente * divisor) + resto
        if (compare(remainder,divisor) < 0) {       // resto < b
            remainder = remainder+dividend[0];      // descer um dígito de a
            dividend.erase(0,1);                    // atualizar a
            if (compare(remainder,divisor) < 0) {   // resto continua menor
                quotient = quotient+'0';
                continue;                           // descer mais um dígito
            }
        }
        // encontrar múltiplo e inserir ao quociente
        for (int i = 1; i <= 10; ++i) {
            if (multiple[i] == "0") multiple[i] = multiply(divisor,i);
            // múltiplo = resto (m = 0), usar o múltiplo 
            // múltiplo > resto (m = 1), usar o múltiplo anterior
            int m = compare(multiple[i],remainder);
            if (m >= 0) {
                quotient = quotient+to_string(i-m);
                remainder = difference(remainder,multiple[i-m]);
                break;
            }
        }   
    }
    return {validate(quotient), validate(remainder)};
}

void testequal(string a, string b, vector<string> sol)
{
    vector<string> ans = divide_strings(a,b);
    // cout << "divide   : " << a << "/" << b << endl;
    // cout << "quotient : " << ans[0] << endl;
    // cout << "remainder: " << ans[1] << endl;
    // cout << "test     : ";
    cout << boolalpha << (ans == sol) << endl;
}

int main()
{
    // teste: validate(num)
    cout << boolalpha << (validate("") == "0") << endl;
    cout << boolalpha << (validate("0") == "0") << endl;
    cout << boolalpha << (validate("9") == "9") << endl;
    cout << boolalpha << (validate("01") == "1") << endl;
    cout << boolalpha << (validate("10") == "10") << endl;
    cout << boolalpha << (validate("00000000") == "0") << endl;
    cout << boolalpha << (validate("00000001") == "1") << endl;

    // teste: compare(num1,num2)
    cout << boolalpha << (compare("","")  == 0) << endl;
    cout << boolalpha << (compare("","0") == 0) << endl;
    cout << boolalpha << (compare("0","") == 0) << endl;    
    cout << boolalpha << (compare("1","") == 1) << endl;
    cout << boolalpha << (compare("0100","010") ==  1) << endl;
    cout << boolalpha << (compare("0100","100") ==  0) << endl;
    cout << boolalpha << (compare("0010","100") == -1) << endl;

    // teste: multiply(num,digit)
    cout << boolalpha << (multiply("",    1) ==    "0") << endl;
    cout << boolalpha << (multiply("0",   1) ==    "0") << endl;
    cout << boolalpha << (multiply("10", -1) ==    "0") << endl;
    cout << boolalpha << (multiply("10", 10) ==    "0") << endl;
    cout << boolalpha << (multiply("101", 0) ==    "0") << endl;
    cout << boolalpha << (multiply("005", 1) ==    "5") << endl;
    cout << boolalpha << (multiply("005", 2) ==   "10") << endl;
    cout << boolalpha << (multiply("101", 2) ==  "202") << endl;
    cout << boolalpha << (multiply("105", 9) ==  "945") << endl;
    cout << boolalpha << (multiply("900", 9) == "8100") << endl;
    cout << boolalpha 
        << (multiply("123456789123456789", 9) == "1111111102111111101") 
        << endl;

    // teste: difference(num1,num2)
    cout << boolalpha << (difference("000","00") == "0") << endl;
    cout << boolalpha << (difference("001","00") == "001") << endl;
    cout << boolalpha << (difference("000","01") == "001") << endl;
    cout << boolalpha << (difference("010","02") == "008") << endl;
    cout << boolalpha << (difference("001","10") == "009") << endl;
    cout << boolalpha 
         << (validate(difference("000000000000000001","10")) == "9")
         << endl;
    cout << boolalpha
         << (validate(difference("10","000000000000000001")) == "9")
         << endl;
    string n1 = "445178889256947331212068434699646460659770965423856783926948"
        "7711076309";
    string n2 =  "26637938253752614803062204932891023808548038660452139421875"
        "3982496339";
    string d  = "418540951003194716409006229766755436851222926763404644505073"
        "3728579970";
    cout << boolalpha << (difference(n1,n2) == d) << endl;

    // teste: divide_strings(a, b) - cálculos rápidos
    testequal("","",vector<string>{"0","0"});
    testequal("1","",vector<string>{"0","1"});
    testequal("1","0",vector<string>{"0","1"});
    testequal("0","0000",vector<string>{"0","0"});
    testequal("0001","00",vector<string>{"0","1"});
    testequal("0001","01",vector<string>{"1","0"});
    testequal("0005","10",vector<string>{"0","5"});
    testequal("0","5",vector<string>{"0","0"});
    testequal("4","5",vector<string>{"0","4"});
    testequal("5","5",vector<string>{"1","0"});
    testequal("10","2",vector<string>{"5","0"});
    testequal("20","3",vector<string>{"6","2"});
    testequal("60","5",vector<string>{"12","0"});
    testequal("219","11",vector<string>{"19","10"});
    testequal("729","9",vector<string>{"81","0"});
    testequal("1000","10",vector<string>{"100","0"});
    testequal("600001","100",vector<string>{"6000","1"});
    testequal("2978400640","64501",vector<string> {"46176","2464"});
    testequal("3297186348","40046",vector<string>{"82334","38984"});
    testequal("10000000000","10",vector<string>{"1000000000","0"});
    testequal("9999999999999999","10",vector<string>{"999999999999999","9"});

    // teste: divide_strings(a, b) - cálculos lentos
    testequal("100000000000000000","10",
        vector<string>{"10000000000000000","0"});
    testequal("1000000000000000001","10",
        vector<string>{"100000000000000000","1"});
    testequal("1000000100000000000","10",
        vector<string>{"100000010000000000","0"});
    testequal("9223372036854775807","2147483647",
        vector<string>{"4294967298","1"});
    testequal("9223372036854775808", "2147483648",
        vector<string> {"4294967296", "0"});

    // teste: divide_strings(a, b) - cálculos lentos - grandes números 
    string a = "445178889256947331212068434699646460659770965423856783926948"
        "7711076309884510481577779567938383690474584147994184225269426075391"
        "964038100021";
    string b = "266379382537526148030622049328910238085480386604521394218753"
        "982496339";
    string q = "167122126726242724338793305461395810399655118065556394842678"
        "20279584925";
    string r = "160457746294133943214413803163005924894352995080439064091293"
        "786010446";
    testequal(a,b,vector<string>{q,r});     

    a = "3100805257217328263160177686720193548748061096658472180148976073408"
        "2363275832760624460569394374469762155754678035950419929485979625860"
        "39015046960298658650261664966531670730499010";
    b = "5753049012607096432584848328910720768387137567305538339706212990655"
        "41068126649601749";
    q = "5389846758514131339774659169798066264351443190854198823225576103123"
        "128375619051014288634743030";
    r = "3250051274077324079058395592962424562517955059488258623438067460311"
        "1749996276939540";
    testequal(a,b,vector<string>{q,r}); 

    return 0;
}
