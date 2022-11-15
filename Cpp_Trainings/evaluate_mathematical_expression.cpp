/*
CODEWARS
https://www.codewars.com/kata/52a78825cdfc2cfc87000005

"Evaluate mathematical expression"
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const string EMPTY = "";
const string SPACE = " ";
const char SEPARATOR = '.';
const string OPERATOR = "+-*/";
const char LPARENTHESES = '(';
const char RPARENTHESES = ')';
const string DIGITS = "0123456789";
const string OPERAND = DIGITS + SEPARATOR;

string search_and_replace(string str, const string &search, const string &replace)
{
    size_t pos = 0;
    while ((pos = str.find(search, pos)) != string::npos) {
        str.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return str;
}

int precedence(char key)
{
    switch (key) {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    default:
        return 0;
    }
}

vector<string> prepare(string expression)
{
    // fix
    // cout << expression << endl;
    expression = search_and_replace(expression, SPACE, EMPTY);
    if (expression.front() == '-' || expression.front() == '+') {
        expression = "0" + expression;
    }
    expression = search_and_replace(expression, "--", "+");
    expression = search_and_replace(expression, "+-", "-");
    expression = search_and_replace(expression, "*+", "*");
    expression = search_and_replace(expression, "/+", "/");
    expression = search_and_replace(expression, "*-", "*(0-1)*");
    expression = search_and_replace(expression, "/-", "*(0-1)/");
    expression = search_and_replace(expression, "(-", "(0-");

    stack<char> stk;
    string str = EMPTY;
    vector<string> tokens;

    // infix to postfix
    for (auto c : expression) {

        if (OPERAND.find(c) != string::npos) {
            str += c;
            continue;
        }
        if (c == LPARENTHESES) {
            stk.push(c);
        }
        if (c == RPARENTHESES) {
            while (stk.top() != LPARENTHESES) {
                if (!str.empty()) {
                    tokens.push_back(str);
                    str = "";
                }
                str += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        if (OPERATOR.find(c) != string::npos) {
            while (!stk.empty() && precedence(c) <= precedence(stk.top())) {
                if (!str.empty()) {
                    tokens.push_back(str);
                    str = "";
                }
                str += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        if (!str.empty()) {
            tokens.push_back(str);
            str = "";
        }
    }

    while (!stk.empty()) {
        if (!str.empty()) {
            tokens.push_back(str);
            str = "";
        }
        str += stk.top();
        stk.pop();
    }

    if (!str.empty()) {
        tokens.push_back(str);
        str = "";
    }

    return tokens;
}

double calc(string expression)
{
    stack<double> numbers;

    for (auto c : prepare(expression)) {

        if (OPERATOR.find(c) != string::npos) {

            auto operand2 = numbers.top();
            numbers.pop();
            auto operand1 = numbers.top();
            numbers.pop();

            if (c ==  "+") {
                numbers.push(operand1 + operand2);
                continue;
            }
            if (c ==  "-") {
                numbers.push(operand1 - operand2);
                continue;
            }
            if (c ==  "*") {
                numbers.push(operand1 * operand2);
                continue;
            }
            if (c ==  "/") {
                if (operand2 != 0) {
                    numbers.push(operand1 / operand2);
                }
                continue;
            }
        }
        else {
            numbers.push(stof(c));
        }
    }

    return numbers.top();
}

void testequal(double ans, double sol)
{
    // cout << "ans: " << ans << "\nsol: " << sol << '\n';
    cout << boolalpha << (ans == sol) << '\n';
}

int main()
{
    testequal(calc("1 + 1"), 2);
    testequal(calc("8/16"), 0.5);
    testequal(calc("3 -(-1)"), 4);
    testequal(calc("2 + -2"), 0);
    testequal(calc("10- 2- -5"), 13);
    testequal(calc("(((10)))"), 10);
    testequal(calc("3 * 5"), 15);
    testequal(calc("-7 * -(6 / 3)"), 14);
    testequal(calc("1-1"), 0);
    testequal(calc("1 -1"), 0);
    testequal(calc("1- 1"), 0);
    testequal(calc("1 - 1"), 0);
    testequal(calc("1- -1"), 2);
    testequal(calc("1 - -1"), 2);
    testequal(calc("1--1"), 2);
    testequal(calc("6 + -(4)"), 2);
    testequal(calc("6 + -( -4)"), 10);

    return 0;
};
