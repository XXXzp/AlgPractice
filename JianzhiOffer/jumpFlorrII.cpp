#include<math.h>
#include<iostream>
using namespace std;


int jumpFloorII(int number) {
    if(number<=0)
        return 0;
    return pow(2,number-1);
}


int main(){
    cout<<jumpFloorII(2)<<endl;
    cout<<jumpFloorII(3)<<endl;
    cout<<jumpFloorII(4)<<endl;
    cout<<jumpFloorII(5)<<endl;
    return 0;
}