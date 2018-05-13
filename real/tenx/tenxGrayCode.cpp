#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;
    
vector<string> getGray(int n) {
    vector<string> result;
    if(n==1){
        string code0("0");
        string code1("1");
        result.push_back(code0);
        result.push_back(code1);
    }else{
        result = getGray(n-1);
        auto result_reversed(result);
        reverse(result_reversed.begin(),result_reversed.end());
        for(auto &str:result){
            str.insert(str.begin(),'0');
        }
        for(auto &str:result_reversed){
            str.insert(str.begin(),'1');
        }
        result.insert(result.end(),result_reversed.begin(),result_reversed.end());
    }
    return result;

}
int main(){
    int i1 = 4;
    auto v2 = getGray(i1);
    cout<<v2.size()<<endl;
    for(auto val:v2){
        cout<<val<<endl;
    }
}