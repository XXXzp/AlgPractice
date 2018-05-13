#include<iostream>

#include<unordered_map>
#include<vector>
using namespace std;

int getValue(vector<int> gifts, int n) {
    
    unordered_map<int,int> counter;
    int maxMoneyOcurred = 0;
    int maxCount = 0;
    int curGifts;

    for(int val:gifts){
        if(counter.find(val)!=counter.end()){
            counter[val]++;
            if(maxCount<counter[val]){
                maxCount=counter[val];
                maxMoneyOcurred = val;
            }
        }else{
            counter.insert(unordered_map<int,int>::value_type(val,1));
        }
    }
    if(maxCount>n/2)
        return maxMoneyOcurred;
    else
        return 0;
}
int main(){
    vector<int> gifts = {1,2,3,2,2};
    cout<<getValue(gifts,5);
    return 0;
}