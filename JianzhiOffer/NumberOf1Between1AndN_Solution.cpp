#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;    
    int NumberOf1Between1AndN_SolutionBBBBBAAAAADDDDDD(int n)
    {
        int counter = 0;
        int temp;
        while(n>0){
            temp = n;
            while(temp>0){
                if(temp%10==1)
                    counter++;
                temp /= 10;
            }
            n--;
        }
        return counter;
    }

int main(){
    cout<<NumberOf1Between1AndN_Solution(3)<<endl;
    cout<<NumberOf1Between1AndN_Solution(1300)<<endl;
    return 0;
}