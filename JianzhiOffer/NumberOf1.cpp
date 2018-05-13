#include<iostream>
using namespace std;


int  NumberOf1(int n) {
    uint32_t usignedn = n;
    int count = 0;
    while(usignedn>0){
        if(usignedn%2==1)
            count++;
        usignedn >>= 1;
    }
    return count;
}
void print(int x){
    cout<< x<<endl;
}
int main(){
    print(NumberOf1(-255));
    return 0;
}

