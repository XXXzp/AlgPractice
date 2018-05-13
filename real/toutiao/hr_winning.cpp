#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("hr_winning.in","r",stdin);
    int NSize = 0;
    int mSize,axSize;
    int lastMan,lastAx,axIndex;
    
    bool man[10^7]={false};
    int Ax[10^7]={0};
    int outSize = 0;
    int i,distance;
    cin>>NSize;
    while(NSize!=0){
        // init
        cin>>mSize>>axSize;
        for( i=0;i<axSize;i++)
            cin>>Ax[i];
        for( i=0;i<mSize;i++)
            man[i]=true;//都活着

        lastMan = 0;
        lastAx = 0;
        axIndex = 0;
        // t 人循环
        while(outSize!=mSize-1){
            lastAx = Ax[(axIndex)%axSize];//抽ax
            for( i=0,distance=0;i<lastAx;){
                if(man[(lastMan+distance)%mSize]){
                    i++;
                    if(i==lastAx){
                        man[(lastMan+distance)%mSize]=false;
                        cout<<(lastMan+distance)%mSize<<"kicked"<<endl;
                        lastMan = (lastMan+distance+1)%mSize;
                    }
                }
                distance++;
            }
            outSize++;
            axIndex++;
        }
        for(i=0;i<mSize;i++)
            if(man[i])
                cout<<i<<endl;
        NSize--;
    }
    return 0;
}