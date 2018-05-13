#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("comment_count_test.in","r",stdin);
    char ch;
    int counter = 0;
    enum readerState {string_state, open_state, single_comment_sig, line_comment, block_comment,block_exiting};
    enum readerState current_state ;
    current_state = open_state;
    while(ch=cin.get()){
        if(ch==EOF)
            break;
        cout<<ch;
        switch(current_state){
            case open_state:
                switch(ch){
                case '\"' :current_state = string_state;break;
                case '/' : current_state = single_comment_sig;break;
                }
                break;
            case string_state:
                if(ch=='\"')
                    current_state = open_state;
                break;
            case single_comment_sig:
                if(ch=='*'){
                    current_state = block_comment;
                }
                else if(ch=='/'){
                    current_state = line_comment;
                }
                else
                    current_state = open_state;
                break;
            case line_comment:
                if(ch=='\n'){
                    current_state = open_state;
                    counter++;
                    //cout<<"add from line"<<endl;
                }
                break;
                    
            case block_comment:
                if(ch=='*')
                    current_state = block_exiting;
                break;
            case block_exiting:
                if(ch=='/'){
                    current_state = open_state;
                    counter++;
                    //cout<<"add from block"<<endl;
                }
                break;
        }
    }
    if(current_state==line_comment)
        counter++;
    //cout<<"result coming"<<endl;
    cout << counter << endl;
    return 0;
}