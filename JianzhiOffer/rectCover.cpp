#include<iostream>
using namespace std;
void print(int x){
    cout<< x<<endl;
}
int rectCover(int number) {
    if(number<=0)
        return 0;
    if(number==1)
        return 1;
    if(number==2)
        return 2;
    int last_One=2,last_two=1,result;
    for(int i=3;i<number+1;++i){
        result = last_One + last_two;
        last_two = last_One;
        last_One = result;
    }
    return result;

}

int main(){
    print(rectCover(3));
    print(rectCover(4));
    print(rectCover(5));
    return 0;
}