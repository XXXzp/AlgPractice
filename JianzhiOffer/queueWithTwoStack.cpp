#include<stack>
#include<iostream>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        int result;
        if(stack1.empty()){
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        result = stack1.top();
        stack1.pop();
        
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution so;
    so.push(10);
    so.push(20);
    cout<< so.pop()<<endl;
    cout<< so.pop()<<endl;
    so.push(30);
    so.push(31);
    cout<< so.pop()<<endl;
    so.push(32);
    cout<< so.pop()<<endl;
    cout<< so.pop()<<endl;
    return 0;
}