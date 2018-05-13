#include<iostream>
#include<vector>
#include<stack>
using namespace std;

    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        int positionPop = 0;
        int positionPush = 0;
        while(positionPop<pushV.size()){
            if(pushV[positionPush] == popV[positionPop]){
                positionPush++;
                positionPop++;
            }else if(!stk.empty()&&stk.top()==popV[positionPop]){
                positionPop++;
                stk.pop();
            }else{
                stk.push(pushV[positionPush]);
                positionPush++;
            }
        }
        while(!stk.empty()&&stk.top()==popV[positionPop]){
            positionPop++;
            stk.pop();
        }
        return stk.empty();
    }

int main(){
    vector<int> in = {1,2,3,4,5};
    vector<int> case1 = {4,5,3,2,1};
    vector<int> case2 = {4,3,5,1,2};
    vector<int> case3 = {5,4,3,2,1};
    stack<int> stk;
    cout<<stk.top()<<endl;
    cout<<"here"<<endl;

    if(IsPopOrder(in,case1))
        cout<<"case1"<<endl;
    if(IsPopOrder(in,case2))
        cout<<"case2"<<endl;
    if(IsPopOrder(in,case3))
        cout<<"case3"<<endl;
    return 0;
}