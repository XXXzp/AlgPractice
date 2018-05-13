#include<iostream>
#include<vector>
using namespace std;

    void reOrderArray(vector<int> &array) {
        vector<int>odd,even;
        for(int val:array){
            if(val%2==1)
                odd.push_back(val);
            else
                even.push_back(val);
        }
        odd.insert(odd.end(),even.begin(),even.end());
        array.assign(odd.begin(),odd.end());
    }

int main(){
    vector<int> in={1,2,3,4,5,6};
    reOrderArray(in);
    for (int val:in)
        cout<<val<<endl;
    return 0;
}