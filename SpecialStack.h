#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class SpecialStack {
private:
    stack<int> st;

public:
    void push(int value);
    void pop();
    int peek() const;
    bool empty() const;
    void printStack() const;
    void popEven();
    void popOdd();
};

#endif