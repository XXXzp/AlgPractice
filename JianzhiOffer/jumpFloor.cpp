#include<iostream>
using namespace std;

int jumpFloor(int number) {
    if(number<=0)
        return 0;
    if(number==1)
        return 1;
    if(number==2)
        return 2;
    
    int num_m_one = 2,num_m_two = 1,result;
    for(int i = 3;i<number+1;++i){
        result = num_m_one + num_m_two;
        num_m_two = num_m_one;
        num_m_one = result;
    }
    return result;
}
int main(){
    cout<<jumpFloor(3)<<endl;
    cout<<jumpFloor(4)<<endl;
        cout<<jumpFloor(5)<<endl;
    return 0;
}