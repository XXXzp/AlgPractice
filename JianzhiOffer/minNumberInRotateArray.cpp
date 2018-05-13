#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(!rotateArray.size())
            return 0;
        for(int i = 1; i<rotateArray.size() ; ++i){
            if(rotateArray[i-1]>rotateArray[i])
                return rotateArray[i];
        }
        return rotateArray[0];
    }
};

int main(){
    Solution so;
    vector<int> arry = {1,2,3,4,5};
    cout<< so.minNumberInRotateArray(arry)<<endl;
    return 0;
}