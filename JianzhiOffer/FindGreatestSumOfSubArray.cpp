#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;    
    
    int FindGreatestSumOfSubArray(vector<int> array) {
        int curMax = 0;
        int globalMax = array[0];
        for(int val:array){
            if(curMax>=0)
                curMax += val;
            else
                curMax = val;
            if(curMax>globalMax)
                globalMax = curMax;
        }
        return globalMax;
    }

int main(){
    vector<int> in = {1,-2,3,10,-4,7,2,-5};
    vector<int> in2 = {-8,-3,-1,-4,2};
    cout<<FindGreatestSumOfSubArray(in)<<endl;
    cout<<FindGreatestSumOfSubArray(in2)<<endl;
    return 0;
}