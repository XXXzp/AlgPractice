#include<iostream>
using namespace std;
    double Power(double base, int exponent) {
        if(exponent==0)
            return 1.0;

        if(exponent<0){
            base = 1/base;
            exponent = -exponent;
        }
        double result=base;
        for(int i = exponent ;i>1; --i){
            result *= base;
        }
        
        return result;
    }

void print(int x){
    cout<< x<<endl;
}
int main(){
    print(Power(0.5,-2));
    return 0;
}