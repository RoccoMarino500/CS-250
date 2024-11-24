#include "SpecialStack.h"
#include <iostream>
using namespace std;

void SpecialStack::push(int value) {
    stack<int> tempStack;

    while (!st.empty()) {
        tempStack.push(st.top());
        st.pop();
    }

    tempStack.push(value);

    while (!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }
}

void SpecialStack::pop() {
    if (st.empty()) {
        throw runtime_error("Stack is empty. Cannot pop.");
    }

    stack<int> tempStack;

    while (!st.empty()) {
        tempStack.push(st.top());
        st.pop();
    }

    tempStack.pop();

    while (!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }
}

int SpecialStack::peek() const {
    if (st.empty()) {
        throw runtime_error("Stack is empty. Cannot peek.");
    }

    stack<int> tempStack = st;
    int topElement = -1;

    while (!tempStack.empty()) {
        topElement = tempStack.top();
        tempStack.pop();
    }

    return topElement;
}

bool SpecialStack::empty() const {
    stack<int> tempStack = st;
    bool isEmpty = true;

    while (!tempStack.empty()) {
        isEmpty = false;
        tempStack.pop();
    }

    return isEmpty;
}

void SpecialStack::printStack() const {
    if (st.empty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    stack<int> tempStack = st;

    while (!tempStack.empty()) {
        cout << tempStack.top() << endl;
        tempStack.pop();
    }
}

void SpecialStack::popEven() {
    stack<int> tempStack;
    bool found = false;

    while (!st.empty()) {
        if (!found && st.top() % 2 == 0) {
            st.pop();
            found = true;
        } else {
            tempStack.push(st.top());
            st.pop();
        }
    }

    while (!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        throw runtime_error("No even number found in the stack.");
    }
}

void SpecialStack::popOdd() {
    stack<int> tempStack;
    bool found = false;

    while (!st.empty()) {
        if (!found && st.top() % 2 != 0) {
            st.pop();
            found = true;
        } else {
            tempStack.push(st.top());
            st.pop();
        }
    }

    while (!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        throw runtime_error("No odd number found in the stack.");
    }
}