class Solution {
public:
    string longestPalindrome(string s) {
        int i,j,k;
        int maxStart=0,maxLen=1;
        int size = s.size();
        if(size<=1){
            return s;
        }
        for (i = 0 ;i<size;){
            if(size - i <=(maxLen/2)){
                break;
            }
            k = i;
            j = i;
            while(k<size-1&&s[k]==s[k+1]){
                k++;
            }
            i = k+1;
            while(k<size-1&&j>0&&s[j-1]==s[k+1]){
                k++;j--;
            }
            if(k-j+1>maxLen){
                maxStart = j;maxLen = k-j+1;
            }
            
        }
        return s.substr(maxStart,maxLen);
    }
    
};