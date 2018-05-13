#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;    
    
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if(k==0||k>input.size())
            return res;
        res.assign(input.begin(),input.begin()+k);
        make_heap(res.begin(),res.end());

        for(int i=k ; i<input.size() ;i++){
            if(input[i]<res[0]){
                pop_heap(res.begin(),res.end());   // 把最大值放在back的位置，其他的调整为最大堆
                res.back() = input[i];
                push_heap(res.begin(),res.end());
            }
        }
        sort_heap(res.begin(),res.end());   //原来是最大堆，输出2，1，0，所以这里排序使其从小到大
        return res;
    }


int main(){
    vector<int> input = {3,5,1,7,4,2,8,6,7,9,0};
    input = GetLeastNumbers_Solution(input,3);
    for(auto val:input)
        cout<<val<<endl;
    return 0;
}