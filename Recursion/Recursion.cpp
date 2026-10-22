#include "Recursion.h"
#include <iostream>
#include <stdexcept>                // std::invalid_argument
using namespace std;

// ============================ Q1 / Q2 ============================
void countdown(int n)
{
    cout << "Entering countdown(" << n << "), stack level " << n << endl;
    if (n <= 0) {
        cout << "Base case reached!" << endl;
        return;                     // base case: no further call
    }
    cout << n << " ";               // work BEFORE the recursive call
    countdown(n - 1);               // recursive call: one level deeper
    cout << "Exiting countdown(" << n << ")" << endl;   // work AFTER
}

void buggyCountdown(int n)
{
    cout << n << " ";
    buggyCountdown(n - 1);          // no base case: never stops
}

void fixedCountdown(int n)
{
    // TODO: add the base case, then the same two lines as buggyCountdown
}

// ============================ Q3 / Q4 ============================
void tailPrint(int n)
{
    // TODO: base case; print n; recursive call
}

void nonTailPrint(int n)
{
    // TODO: base case; recursive call; print n
}

int tailSum(int n, int accumulator)
{
    return 0;                       // TODO
}

int nonTailSum(int n)
{
    return 0;                       // TODO
}

// ============================ Q5 ============================
long long factorial(int n)
{
    // TODO: throw invalid_argument("...") when n < 0; base case; n * ...
    return 0;
}

long long factorialTail(int n, long long acc)
{
    return 0;                       // TODO
}

// ============================ Q6 ============================
double power(double base, int exponent, int& calls)
{
    calls++;                        // keep this line: it counts the calls
    return 0;                       // TODO
}

double fastPower(double base, int exponent, int& calls)
{
    calls++;
    return 0;                       // TODO
}

// ============================ Q7 ============================
bool isEven(int n)
{
    return false;                   // TODO: base case, then isOdd(n - 1)
}

bool isOdd(int n)
{
    return false;                   // TODO: base case, then isEven(n - 1)
}

// ============================ Q9 ============================
void parseExpression(const string& expr, int& index)
{
    cout << "Entering parseExpression at index " << index << endl;
    while (index < (int)expr.length() && expr[index] != ')') {
        if (isdigit(expr[index])) {
            parseOperand(expr, index);
        }
        else if (expr[index] == '+' || expr[index] == '*' ||
                 expr[index] == '-') {
            cout << "Operator: " << expr[index] << endl;
            index++;
        }
        else if (expr[index] == '(') {
            parseOperand(expr, index);          // indirect recursion
        }
        else {
            index++;                            // skip spaces etc.
        }
    }
    if (index < (int)expr.length() && expr[index] == ')') {
        cout << "Closing parenthesis at index " << index << endl;
        index++;                                // move past ')'
    }
    cout << "Exiting parseExpression at index " << index << endl;
}

void parseOperand(const string& expr, int& index)
{
    if (isdigit(expr[index])) {
        cout << "Operand: " << expr[index] << endl;
        index++;
    }
    else if (expr[index] == '(') {
        cout << "Opening parenthesis at index " << index << endl;
        index++;                                // skip '('
        parseExpression(expr, index);           // indirect recursion
    }
}

// ============================ Q10 ============================
long long fib(int n, long long& calls)
{
    calls++;                        // keep this line
    return 0;                       // TODO: two recursive calls
}

long long fibIter(int n)
{
    return 0;                       // TODO: a loop, no recursion
}
