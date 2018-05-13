#include<iostream>
using namespace std;
int Fibonacci(int n) {
    if(n<=0)
        return 0;
    if(n==1||n==2){
        return 1;
    }
    int Fi_n_minus_one=1,Fi_n_minus_two=1;
    int Fi_temp;
    for(int i = 3;i<n+1;i++){
        Fi_temp = Fi_n_minus_one + Fi_n_minus_two;
        Fi_n_minus_two = Fi_n_minus_one;
        Fi_n_minus_one = Fi_temp;
    }
    return Fi_temp;
}
int main(){
    cout<<Fibonacci(13)<<endl;
    cout<<Fibonacci(3)<<endl;
    return 0;
}