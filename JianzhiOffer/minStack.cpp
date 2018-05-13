#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        stk.push(value);
        if(mstk.empty()||mstk.top()>value)
            mstk.push(value);
    }
    void pop() {
        if(mstk.top()==stk.top())
            mstk.pop();
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return mstk.top();
    }
private:
    stack<int> stk;
    stack<int> mstk;
};