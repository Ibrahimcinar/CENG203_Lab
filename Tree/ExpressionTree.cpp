#include "ExpressionTree.h"
#include <iostream>
#include <sstream>                  // stringstream: splits the tokens
#include <stack>                    // std::stack: Week 4's Stack, any type
#include <stdexcept>                // runtime_error
using namespace std;

bool isOperator(const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// ============================ Q8 ============================
ExprNode* buildFromPostfix(const string& postfix)
{
    stack<ExprNode*> st;            // holds finished subtrees
    stringstream ss(postfix);
    string token;
    while (ss >> token) {           // one token at a time: "3", "4", "+"
        ExprNode* node = new ExprNode;
        node->data = token;
        node->left = nullptr;
        node->right = nullptr;
        if (isOperator(token)) {
            node->right = st.top();     // top of the stack = right operand
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }
    return st.empty() ? nullptr : st.top();
}

void printPrefix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";      // operator first: Polish notation
    printPrefix(node->left);
    printPrefix(node->right);
}

void printPostfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    printPostfix(node->left);
    printPostfix(node->right);
    cout << node->data << " ";      // operator last: reverse Polish
}

// ============================ Q9 ============================
void printInfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    if (isOperator(node->data)) {
        cout << "(";
        printInfix(node->left);
        cout << " " << node->data << " ";
        printInfix(node->right);
        cout << ")";
    }
    else
        cout << node->data;
}

double evaluate(const ExprNode* node)
{
    if (!isOperator(node->data))
        return stod(node->data);        // a leaf is a number
    double a = evaluate(node->left);    // children first: postorder
    double b = evaluate(node->right);
    if (node->data == "+") return a + b;
    if (node->data == "-") return a - b;
    if (node->data == "*") return a * b;
    if (b == 0)
        throw runtime_error("Division by zero");
    return a / b;
}

void destroyExpr(ExprNode* node)
{
    if (node == nullptr)
        return;
    destroyExpr(node->left);
    destroyExpr(node->right);
    delete node;
}
